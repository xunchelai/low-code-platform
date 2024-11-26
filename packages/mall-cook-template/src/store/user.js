/*
 * @Description: What's this for
 *  
 * @Date: 2022-02-07 09:50:30
 *   
 * @LastEditTime: 2024-02-07 10:18:35
 */
export default {
  state: {
    token: '', // 模拟真实登录
  },
  getters: {
    token: state => state.token,
    isLogin: state => state.token
  },
  mutations: {
    // 设置token
    setToken (state, token) {
      state.token = token
    }
  }
}
