#include <stdio.h>
#include <stdlib.h>
#include <uv.h>

typedef struct context_s
{
    uv_fs_t open_fs;
    uv_buf_t buf;
    const char *filepath;
} context_t;

int buf_size = 3;

void on_read(uv_fs_t *req)
{
    context_t *ctx = req->data;
    if (req->result < 0)
    {
        fprintf(stderr, "[on_read  %s] error file: %s\n", ctx->filepath, uv_strerror((int)req->result));
        return;
    }
    printf("[on_read %s] success, result=%zd \n", ctx->filepath, req->result);
    printf("[on_read %s] buffer=%s\n", ctx->filepath, ctx->buf.base);
}

void on_open(uv_fs_t *req)
{
    uv_loop_t *loop = uv_default_loop();
    context_t *ctx = req->data;
    if (req->result < 0)
    {
        fprintf(stderr, "[on_open %s] error file: %s\n", ctx->filepath, uv_strerror((int)req->result));
        return;
    }
    printf("[on_open %s] success\n", ctx->filepath);
    char *buffer = malloc(sizeof(char) * buf_size);
    ctx->buf = uv_buf_init(buffer, sizeof(char) * buf_size);
    uv_fs_read(loop, req, req->result, &ctx->buf, 1, -1, on_read);
}

int main(const int argc, const char **argv)
{
    uv_loop_t *loop = uv_default_loop();

    int i;
    for (i = 1; i < argc; i++)
    {
        uv_fs_t *req_file = malloc(sizeof(uv_fs_t));
        context_t *ctx = malloc(sizeof(context_t));
        printf("argv %d arg[%d]=%s\n", argc, i, argv[i]);
        ctx->filepath = argv[i];
        req_file->data = ctx;
        uv_fs_open(loop, req_file, argv[i], O_RDONLY, 0, on_open);
    }

    uv_run(loop, UV_RUN_DEFAULT);
    return 0;
}
