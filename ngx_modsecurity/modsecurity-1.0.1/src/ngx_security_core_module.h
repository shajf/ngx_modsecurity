/*
 * =====================================================================================
 *      Copyright (C) 2014 jianfeng sha
 *
 *      Filename:  ngx_security_core_module.h
 *
 *      Description:  
 *
 *      Created:  05/22/14 12:52:01
 *
 *      Author:  jianfeng sha , csp001314@163.com
 * =====================================================================================
 */
#ifndef NGX_SECURITY_CORE_MODULE_H
#define NGX_SECURITY_CORE_MODULE_H


typedef struct ngx_http_security_core_main_conf_s ngx_http_security_core_main_conf_t;
typedef struct ngx_http_security_core_srv_conf_s ngx_http_security_core_srv_conf_t;
typedef struct ngx_http_security_core_loc_conf_s ngx_http_security_core_loc_conf_t;

struct ngx_http_security_core_main_conf_s{
    
    ngx_str_t   *lua_path;
    ngx_str_t   *lua_cpath;
};


struct ngx_http_security_core_srv_conf_s{

};


struct ngx_http_security_core_loc_conf_s{
    
    ngx_flag_t enable_sec_engine;
};


#endif /*NGX_SECURITY_CORE_MODULE_H*/
