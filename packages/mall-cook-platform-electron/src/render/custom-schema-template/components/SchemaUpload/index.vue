<!--
 * @Description: What's this for
 *  
 *   @Date: 2024-09-24 09:11:38
 *   
 * @LastEditTime: 2024-09-26 14:16:11
-->
<template>
  <config-item :label='label'>
    <FaImageUpload
      v-model="mValue"
      v-bind="mOptions"
      :maxCount="1"
    />
  </config-item>
</template>

<script>
import schemaMixin from "@/mixin/schemaMixin";

export default {
  name: "SchemaUpload",

  mixins: [schemaMixin],
};
</script>
