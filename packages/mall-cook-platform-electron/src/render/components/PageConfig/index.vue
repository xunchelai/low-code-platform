<!--
 * @Description: 页面配置
 *  
 *   @Date: 2024-09-22 17:33:51
 *   
 * @LastEditTime: 2024-01-18 16:10:43
-->
<template>
  <div class="p10">
    <config-item label='背景色'>
      <config-color-picker v-model="project.config.backgroundColor"></config-color-picker>
    </config-item>
  </div>
</template>

<script>
import { mapGetters } from "vuex";
export default {
  name: "PageConfig",
  computed: {
    ...mapGetters(["project"]),
  },
};
</script>