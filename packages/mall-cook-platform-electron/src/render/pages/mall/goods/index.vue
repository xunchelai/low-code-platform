<!--
 * @Description: 商品菜单
 *  
 *   @Date: 2024-06-10 16:00:34
 *   
 * @LastEditTime: 2024-09-18 10:44:12
-->
<template>
  <SideBar :groups='groups'></SideBar>
</template>

<script>
import SideBar from "@/components/SideBar/index.vue";
export default {
  components: {
    SideBar,
  },

  data() {
    return {
      groups: [
        {
          label: "模拟商品",
          list: [
            {
              name: "全部商品",
              path: "/mall/goods/goods-manager",
            },
            {
              name: "全部分类",
              path: "/mall/goods/group-manager",
            },
          ],
        },
      ],
    };
  },
};
</script>