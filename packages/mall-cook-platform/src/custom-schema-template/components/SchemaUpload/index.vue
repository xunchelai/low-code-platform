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
