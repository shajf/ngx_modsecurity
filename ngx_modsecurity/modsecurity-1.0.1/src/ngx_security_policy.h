/*
 * =====================================================================================
 *
 *       Copyright (C) 2014 jianfeng sha
 *
 *       Filename:  ngx_security_policy.h
 *
 *       Description:  
 *
 *       Created:  05/23/14 18:33:54
 *
 *       Author:  jianfeng sha , csp001314@163.com
 *
 * =====================================================================================
 */

#ifndef NGX_SECURITY_POLICY_H
#define NGX_SECURITY_POLICY_H


typedef struct ngx_security_policy_s ngx_security_policy_t;
typedef struct ngx_security_policy_manager_s ngx_security_policy_manager_t;


struct ngx_security_policy_manager_s {

};

struct ngx_security_policy_s {
	ngx_uint32_t	id;
	ngx_str_t		name;
	ngx_str_t		desc;
};

#endif /* NGX_SECURITY_POLICY_H */
