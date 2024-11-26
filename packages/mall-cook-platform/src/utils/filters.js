/*
 * @Description: 全局过滤器
 *  
 *   @Date: 2024-09-15 19:48:43
 *   
 * @LastEditTime: 2024-09-16 11:47:12
 */
import Vue from 'vue'

const filters = {
    // 价格显示 分 -> 元  （带两位小数）  
    moneyDec(target) {
        return (target / 100).toFixed(2)
    },

    // 价格显示 分 -> 元
    money(target) {
        return target / 100
    }
}

Object.keys(filters).forEach(key => {
    Vue.filter(key, filters[key])
})