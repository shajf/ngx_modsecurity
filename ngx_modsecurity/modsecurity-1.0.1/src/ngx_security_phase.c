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


static ngx_int_t security_phase_post_read(ngx_http_request_t *r);
static ngx_int_t security_phase_server_rewrite(ngx_http_request_t *r);
static ngx_int_t security_phase_rewrite(ngx_http_request_t *r);
static ngx_int_t security_phase_preaccess(ngx_http_request_t *r);
static ngx_int_t security_phase_access(ngx_http_request_t *r);
static ngx_int_t security_phase_content(ngx_http_request_t *r);
static ngx_int_t security_phase_log(ngx_http_request_t *r);

static ngx_int_t set_phase_handler(ngx_http_core_main_conf_t *cmcf,int phase){

	ngx_http_handler_pt *h;

	h = ngx_array_push(&cmcf->phases[phase].handlers);
	
	if(h == NULL){
		return NGX_ERROR;
	}

	switch(phase){
		
		case NGX_HTTP_POST_READ_PHASE:
			
			*h = security_phase_post_read;
			break;

		case NGX_HTTP_SERVER_REWRITE_PHASE:

			*h = security_phase_server_rewrite;
			break;

		case NGX_HTTP_REWRITE_PHASE:
			
			*h = security_phase_rewrite;
			break;

		case NGX_HTTP_PREACCESS_PHASE:
			
			*h = security_phase_preaccess;
			break;

		case NGX_HTTP_ACCESS_PHASE:

			*h = security_phase_access;
			break;

		case NGX_HTTP_CONTENT_PHASE:

			*h = security_phase_content;
			break;

		case NGX_HTTP_LOG_PHASE:

			*h = security_phase_log;
			break;

		default:
			return NGX_ERROR;
	}

	return NGX_OK;
}

ngx_int_t ngx_security_phase_setup(ngx_conf_t *conf){
	
	ngx_http_handler_pt			*h;
	ngx_http_core_main_conf_t 	*cmcf;
	ngx_int_t 					status;

	cmcf = ngx_http_conf_get_module_main_conf(cf,ngx_http_core_module);
	
	status = NGX_OK;
	
	do{
		
		status = set_phase_handler(cmcf,NGX_HTTP_POST_READ_PHASE);
		if(status == NGX_ERROR) break;

		status = set_phase_handler(cmcf,NGX_HTTP_SERVER_REWRITE_PHASE);
		if(status == NGX_ERROR) break;
		
		status = set_phase_handler(cmcf,NGX_HTTP_REWRITE_PHASE);
		if(status == NGX_ERROR) break;

		status = set_phase_handler(cmcf,NGX_HTTP_PREACCESS_PHASE);
		if(status == NGX_ERROR) break;

		status = set_phase_handler(cmcf,NGX_HTTP_ACCESS_PHASE);
		if(status == NGX_ERROR) break;

		status = set_phase_handler(cmcf,NGX_HTTP_CONTENT_PHASE);
		if(status == NGX_ERROR) break;

		status = set_phase_handler(cmcf,NGX_HTTP_LOG_PHASE);
		if(status == NGX_ERROR) break;

	}while(0);

	return status;
}


