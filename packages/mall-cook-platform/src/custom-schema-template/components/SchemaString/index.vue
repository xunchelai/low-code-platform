<!--
 * @Description: What's this for
 *  
 *   @Date: 2024-09-24 09:11:38
 *   
 * @LastEditTime: 2024-11-10 14:20:53
-->
<template>
  <config-item :label='label'>
    <el-input
      v-model="mValue"
      v-bind="mOptions"
      :placeholder='mOptions.placeholder'
      size='small'
    ></el-input>
  </config-item>
</template>

<script>
import schemaMixin from "@/mixin/schemaMixin";
export default {
  name: "SchemaString",
  mixins: [schemaMixin],
};
</script>