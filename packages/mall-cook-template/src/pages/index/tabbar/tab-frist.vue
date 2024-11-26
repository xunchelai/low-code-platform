<!--
 * @Description: 首页后第一个tabbar页面
 *  
 * @Date: 2022-03-22 10:32:43
 *   
 * @LastEditTime: 2024-03-22 14:45:11
-->
<template>
  <tabbar-page :location="1"></tabbar-page>
</template>

<script>
import tabbarPage from "@/components/tabbar-page";

export default {
  components: {
    tabbarPage,
  },
};
</script>

