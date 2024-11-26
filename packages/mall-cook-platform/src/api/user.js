/*
 * @Description: 用户api
 *  
 *   @Date: 2024-09-22 16:22:01
 *   
 * @LastEditTime: 2024-09-22 16:27:10
 */

import request from '@/utils/request';

/**
 * 登录
 */
export const login = async (data) => request({ url: "/user/login", method: "POST", data });

/**
 * 注册
 */
export const register = async (data) => request({ url: "/user/register", method: "POST", data });
