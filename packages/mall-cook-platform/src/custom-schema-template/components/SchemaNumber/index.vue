<!--
 * @Description: What's this for
 *  
 *   @Date: 2024-09-24 09:11:38
 *   
 * @LastEditTime: 2024-10-18 15:57:23
-->
<template>
  <config-item :label='label'>
    <el-slider
      v-model="mValue"
      v-bind="mOptions"
      show-input
    >
    </el-slider>
  </config-item>
</template>

<script>
import schemaMixin from "@/mixin/schemaMixin";

export default {
  name: "SchemaNumber",

  mixins: [schemaMixin],

  data() {
    return {
      defaultOptions: {
        max: 100,
      },
    };
  },
};
</script>