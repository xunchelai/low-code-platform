<!--
 * @Description: PC头部菜单
-->
<template>
  <div>
    <div class="topBar">
      <!-- 左侧内容 -->
      <span class="f14 pointer" @click="back">切换商城</span>

      <!-- 右侧内容 -->
      <div>
        <!-- <el-button size="small ml10" @click="openImageDialog">添加图片</el-button>
        <el-button size="small" @click="openJsonDialog">JSON Schema</el-button> -->
        <el-button size="small" @click="toSchema">组件属性Json生成器</el-button>
        <!-- <el-button size="small ml10" @click="viewQr">商城二维码</el-button> -->
        <el-button size="small ml10" @click="show = true">实时预览</el-button>
        <el-button size="small f-white bg-theme" @click="openSave">保存</el-button>
        <el-button size="small ml10" @click="onLogout">退出</el-button>
      </div>
    </div>

    <!-- <el-dialog title="请输入图片URL" :visible.sync="imageDialogVisible">
      <el-input type="textarea" v-model="imageUrl" placeholder="请输入图片URL"></el-input>
      <span slot="footer" class="dialog-footer">
        <el-button @click="imageDialogVisible = false">取消</el-button>
        <el-button type="primary" @click="renderImageComponent">确认</el-button>
      </span>
    </el-dialog> -->

    <!-- <el-dialog title="请输入JSON代码" :visible.sync="jsonDialogVisible">
      <el-input type="textarea" v-model="jsonInput" rows="10"></el-input>
      <span slot="footer" class="dialog-footer">
        <el-button @click="jsonDialogVisible = false">取消</el-button>
        <el-button type="primary" @click="renderComponents">确认</el-button>
      </span>
    </el-dialog> -->

    <real-timeView :show.sync="show"></real-timeView>
    <save-dialog ref="save"></save-dialog>
    <qr-dialog ref="qr"></qr-dialog>
  </div>
</template>


<script>
import RealTimeView from "./RealTimeView.vue";
import SaveDialog from "@/components/SaveDialog";
import QrDialog from "@/components/QrDialog";
import { mapGetters, mapMutations } from "vuex";
import { editProject } from "@/api/project";

export default {
  components: {
    RealTimeView,
    SaveDialog,
    QrDialog,
  },
  data() {
    return {
      show: false,
      jsonDialogVisible: false,
      imageDialogVisible: false,
      jsonInput: '',
      imgComponentConfig: null
    };
  },
  created() {
    this.loadComponentConfig();
  },
  methods: {
    ...mapMutations(["logout"]),
    // // async loadComponentConfig() {
    // //   // 根据实际路径调整
    // //   const module = await import('../../../../mall-cook-template/src/widgets/McImg/component.json');
    // //   this.imgComponentConfig = module.default;
    // // },
    // openJsonDialog() {
    //   this.jsonDialogVisible = true;
    // },
    // openImageDialog() {
    //   this.imageDialogVisible = true;
    // },
    // renderComponents() {
    //   const jsonData = JSON.parse(this.jsonInput);
    //   this.sendMessageToIframe(jsonData);
    //   this.jsonDialogVisible = false;
    // },
    // renderImageComponent() {
    //   // 获取 $initializing 中的 McImg 组件信息
    //   const componentInfo = this.$initializing.McImg;

    //   // 深拷贝以避免直接修改 $initializing 的数据
    //   const componentData = JSON.parse(JSON.stringify(componentInfo));

    //   // 更新 imagePath 为用户输入的图片URL
    //   componentData.imageValue.imagePath = this.imageUrl;

    //   this.sendMessageToIframe(componentData);
    //   this.imageDialogVisible = false;
    // },
    sendMessageToIframe(componentData) {
      const iframe = this.$root.control.h5Iframe;
      if (iframe) {
        iframe.contentWindow.postMessage(
          {
            event: 'drop',
            params: componentData
          },
          '*'
        );
      }
    },
    // renderComponents() {
    //   this.jsonDialogVisible = false;
    //   try {
    //     const componentData = JSON.parse(this.jsonInput);
    //     const detailedComponents = componentData.components.map(component => {
    //       if (component.type === "image" && this.imgComponentConfig) {
    //         return this.mapImageComponent(component);
    //       }
    //       return component;
    //     });
        
    //     this.control.h5Iframe.contentWindow.postMessage({
    //       type: 'updateComponents',
    //       components: detailedComponents
    //     }, "*");
    //   } catch (error) {
    //     console.error("JSON解析错误：", error);
    //     this.$notify({
    //       title: '错误',
    //       message: '输入的JSON格式不正确，请检查后重试。',
    //       type: 'error'
    //     });
    //   }
    // },
    // mapImageComponent(component) {
    //   const config = JSON.parse(JSON.stringify(this.imgComponentConfig)); // 深复制配置
    //   config.fields.imageValue.child.imagePath.value = component.url || this.imgComponentConfig.fields.imageValue.child.imagePath.value;
    //   return config;
    // },
    back() {
      this.$router.push({ name: "managet" });
    },
    openSave(view = false) {
      this.$refs.save.open(view);
    },
    toSchema() {
      let { href } = this.$router.resolve({
        path: "/schema",
      });
      window.open(href);
    },
    viewQr() {
      this.$confirm("如不更新，则预览为上次保存的项目数据?", "是否更新保存", {
        confirmButtonText: "更新保存",
        cancelButtonText: "不更新",
        type: "warning",
      }).then(() => {
        this.openSave(true);
      }).catch(() => {
        this.openQr();
      });
    },
    openQr() {
      this.$refs.qr.open();
    },
    save() {
      let data = {
        id: this.project.id,
        userId: this.userInfo.userId,
        name: this.project.name,
        richText: JSON.stringify(this.project),
      };
      editProject(data).then(response => {
        const { status } = response;
        if (status === "10000") {
          this.$notify({
            title: "成功",
            message: "项目保存成功",
            type: "success",
          });
        }
      });
    },
    onLogout() {
      this.$confirm("是否确定退出平台?", "退出", {
        confirmButtonText: "确定",
        cancelButtonText: "取消",
        type: "warning",
      }).then(() => {
        this.logout();
        this.$router.push({ name: "login" });
      });
    },
  },
};
</script>

<style lang="scss" scoped>
.topBar {
  display: flex;
  align-items: center;
  justify-content: space-between;
  height: 56px;
  width: 100%;
  padding: 0 20px;
  background: #fff;
  border-bottom: 1px solid #ebedf0;
}
</style>
