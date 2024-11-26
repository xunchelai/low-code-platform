<!--
 * @Description: What's this for
 *  
 *   @Date: 2024-09-24 09:11:38
 *   
 * @LastEditTime: 2024-09-26 20:35:00
-->
<template>
  <config-item :label='label'>
    <div
      class="flex row-right"
      style="width: calc(100% - 24px);"
    >
      <el-color-picker
        v-model="mValue"
        :predefine="predefineColors"
        v-bind="mOptions"
        show-alpha
      ></el-color-picker>
    </div>
  </config-item>
</template>

<script>
import schemaMixin from "@/mixin/schemaMixin";
import ConfigColorPicker from "./ConfigColorPicker.vue";

export default {
  name: "SchemaColor",

  mixins: [schemaMixin],

  components: {
    ConfigColorPicker,
  },

  data() {
    return {
      predefineColors: [
        "#ffffff",
        "#f5f5f5f5",
        "#F2F2F2",
        "#FF4444",
        "#FFCD00",
        "#3FBC87",
        "#5197FF",
        "#BADCFF",
        "#000000",
      ],
    };
  },
};
</script>