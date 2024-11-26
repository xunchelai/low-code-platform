/*
 * @Description: What's this for
 *  
 *   @Date: 2024-05-19 09:49:33
 *   
 * @LastEditTime: 2024-02-07 09:59:04
 */
import Vue from 'vue'
import Vuex from 'vuex'
import project from './project'
import user from './user'
import order from './order'

Vue.use(Vuex)

export default new Vuex.Store({
  modules: {
    project,
    user,
    order
  }
})
