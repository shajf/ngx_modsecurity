/*
 * =====================================================================================
 *      Copyright (C) 2014 jianfeng sha
 *
 *      Filename:  ngx_security_core_module.c
 *
 *      Description:  
 *
 *      Created:  05/15/14 14:52:00
 *
 *      Author:  jianfeng sha , csp001314@163.com
 *
 * =====================================================================================
 */

#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>

static ngx_command_t ngx_security_core_commands[] = {

    ngx_null_command
};

static ngx_http_module_t ngx_security_core_module_ctx = {

}; 

ngx_module_t ngx_security_core_module = {
    NGX_MODULE_V1,
    &ngx_security_core_module_ctx,
    ngx_security_core_commands,
    NGX_HTTP_MODULE,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NGX_MODULE_V1_PADDING
};
