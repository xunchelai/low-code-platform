/*
 * @Description: What's this for
 *  
 *   @Date: 2024-05-19 09:49:33
 *   
 * @LastEditTime: 2024-09-01 20:18:11
 */
import Vue from 'vue'
import Vuex from 'vuex'
import project from './project'
import user from './user'

Vue.use(Vuex)

export default new Vuex.Store({
  state: {
    ...project.state,
    ...user.state,
  },
  getters: {
    ...project.getters,
    ...user.getters,
  },
  mutations: {
    ...project.mutations,
    ...user.mutations,
  },
  actions: {
  },
  modules: {
  }
})
