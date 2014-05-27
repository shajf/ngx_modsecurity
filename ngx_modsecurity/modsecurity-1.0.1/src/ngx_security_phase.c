/*
 * =====================================================================================
 *      Copyright (C) 2014 jianfeng sha
 *
 *      Filename:  ngx_security_phase.c
 *
 *      Description:  
 *
 *      Created:  05/27/14 16:30:15
 *
 *      Author:  jianfeng sha , csp001314@163.com
 *
 * =====================================================================================
 */


static ngx_int_t security_phase_server_rewrite(ngx_http_request_t *r);
static ngx_int_t security_phase_config_find(ngx_http_request_t *r);
static ngx_int_t security_phase_rewrite(ngx_http_request_t *r);
static ngx_int_t security_phase_post_rewrite(ngx_http_request_t *r);
static ngx_int_t security_phase_preaccess(ngx_http_request_t *r);
static ngx_int_t security_phase_access(ngx_http_request_t *r);
static ngx_int_t security_phase_post_access(ngx_http_request_t *r);
static ngx_int_t security_phase_try_files(ngx_http_request_t *r);
static ngx_int_t security_phase_content(ngx_http_request_t *r);
static ngx_int_t security_phase_log(ngx_http_request_t *r);


ngx_int_t ngx_security_phase_setup(){
    
}

