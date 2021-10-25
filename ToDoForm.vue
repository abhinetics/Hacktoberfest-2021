<template>
  <div>
    <el-form @submit.prevent
      :inline="true"
      :model="formInput"
       class="todo-form-input">
      <el-form-item label="Title" prop="title">
        <el-input v-model="formInput.title" placeholder="Enter new todo"></el-input>
      </el-form-item>
      <el-form-item>
        <el-button type="primary" @click="onSubmit()">Add</el-button>
      </el-form-item>      
    </el-form>
  </div>
</template>

<script lang="ts">
import { ElMessage } from "element-plus";
import { defineComponent,ref } from "vue";
export default defineComponent({
  name: 'TodoForm',
  setup(_,{emit}) {
    // console.log("ep")
    const formInput = ref({ title: '', completed: false})
    const onSubmit = () =>{
      if(formInput.value.title.length > 3){
        emit("send-message",formInput.value)
      } else{
        ElMessage({
          message: "Warning this is not a valid todo",
          type: "warning"
        })
      }
      formInput.value.title = ''
      // console.log("Todo", formInput.value)
    }
  return {
    formInput,
    onSubmit
  }
  }
})
</script>

<style lang="scss" scoped>
</style>
