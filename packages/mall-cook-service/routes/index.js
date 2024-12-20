const compose = require('koa-compose')
const glob = require('glob')
const { resolve } = require('path')

registerRouter = () => {
    let routers = [];
    glob.sync(resolve(__dirname, './', '**/*.js'))
        .filter(value => (value.indexOf('index.js') === -1))
        .map(router => {
            console.log(`Loading router: ${router}`); // 添加调试信息
            routers.push(require(router).routes())
            routers.push(require(router).allowedMethods())
        })
    return compose(routers)
}

module.exports = registerRouter