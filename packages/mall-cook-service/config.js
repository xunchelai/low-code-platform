/*
 * @Description: 配置信息
 */
config = {
  appid: 'xxx', // 小程序appId
  secret: 'xxx', // 小程序secret
  serviceApi: 'http://127.0.0.1:3000', // 服务器地址 用于上传完图片后拼接 详细看routes/upload.js
  mongodbUrl: 'mongodb://localhost:27017/mall-cook', // mongodb数据库地址 格式：mongodb://username:password@host:port/name
  jwtSecret: 'test' // Needed or /login endpoint will throw 500 error
}

module.exports = config
