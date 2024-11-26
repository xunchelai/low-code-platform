<!--
 * @Description: 页面构建
 *  
 *   @Date: 2024-05-19 09:49:33
 *   
 * @LastEditTime: 2024-01-11 20:01:59
-->
<template>
  <div class="build">
    <control />
  </div>
</template>

<script>
import Control from "@/components/Control/index.vue";

export default {
  components: {
    Control,
  },
};
</script>
<style lang="scss" scoped>
.build {
  height: 100vh;
  background: #f7f8fa;
  }
</style>
