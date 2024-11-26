<!--
 * @Description: What's this for
 *  
 *   @Date: 2024-12-15 16:31:43
 *   
 * @LastEditTime: 2024-11-02 09:51:54
-->
<template>
  <img
    src="https://i.niupic.com/images/2022/11/02/aaa1.png"
    @click="toGit"
  />
</template>

<script>
export default {
  name: "GitControl",
  methods: {
    toGit() {
      console.log("toGit");

      window.open("https://github.com/wangyuan389/mall-cook", "_blank");
    },
  },
};
</script>

<style lang="scss" scoped>
img {
  width: 30px;
  margin-right: 15px;
  cursor: pointer;
}
</style>