/*
 * @Description: What's this for
 *  
 *   @Date: 2024-08-17 14:28:29
 *   
 * @LastEditTime: 2024-03-02 15:13:34
 */
const tools = require('../utils/tools')
const multer = require('koa-multer');
const Router = require('koa-router')
const config = require('../config')

const router = new Router()


//文件上传
const path = require('path');

var storage = multer.diskStorage({
  // 文件保存路径
  destination: function (req, file, cb) {
    const uploadPath = path.join(__dirname, '../public/img/');
    console.log(`File will be saved to: ${uploadPath}`);
    cb(null, uploadPath);
  },
  // 修改文件名称
  filename: function (req, file, cb) {
    var fileFormat = (file.originalname).split(".");
    const filename = Date.now() + "." + fileFormat[fileFormat.length - 1];
    console.log(`File will be named: ${filename}`);
    cb(null, filename);
  }
});


//加载配置
var upload = multer({ storage: storage });


//路由
router.post('/upload', upload.single('file'), async (ctx, next) => {
  ctx.body = {
      data: `${config.serviceApi}/img/${ctx.req.file.filename}`,
      errorCode: "00000",
      message: "请求成功",
  }
  ctx.status = 200
})

module.exports = router

