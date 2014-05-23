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

    {   ngx_string("sec_engine"),
        NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_LOC_CONF|NGX_CONF_FLAG|NGX_HTTP_SIF_CONF|NGX_HTTP_LIF_CONF,
        ngx_security_engine,
        NGX_HTTP_LOC_CONF_OFFSET,
        offsetof(ngx_http_security_core_loc_conf_t,enable_sec_engine),
        NULL},

    {   ngx_string("lua_package_path"),
        NGX_HTTP_MAIN_CONF|NGX_CONF_TAKE1,
        ngx_security_lua_path,
        NGX_HTTP_MAIN_CONF_OFFSET,
        0,
        NULL
    },
    
    {   ngx_string("lua_package_cpath"),
        NGX_HTTP_MAIN_CONF|NGX_CONF_TAKE1,
        ngx_security_lua_cpath,
        NGX_HTTP_MAIN_CONF_OFFSET,
        0,
        NULL
    },

    {   ngx_string("sec_policy"),
        NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_LOC_CONF|NGX_CONF_TAKE1,
        ngx_security_policy,
        NGX_HTTP_LOC_CONF_OFFSET,
        0,
        NULL
    },
	
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
