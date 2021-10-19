<template>
  <q-dialog v-model="open" @hide="this.onCancel()" >
      <q-card class="my-card bg-grey-2 text-black">
      <q-card-section>
        <div class="text-h6">Are you sure you want to delete this?</div>
        <div class="text-subtitle2"></div>
      </q-card-section>

      <q-card-actions>
        <q-btn flat class="bg-blue-grey-2 text-black" @click="this.onCancel()">Cancel</q-btn>
        <q-btn flat class="bg-red text-white" icon="delete_forever" @click="this.onConfirm()">Confirm</q-btn>
      </q-card-actions>
    </q-card>

    </q-dialog>
</template>

<script>
export default {
  props: {
    url: {
      type: String,
      required: true
    }
  },
  data () {
    return {
      open: false,
      id: ''
    }
  },
  methods: {
    openDialog (id) {
      this.id = id
      this.open = true
    },
    onConfirm () {
      this.$store.dispatch(`${this.url}/delete_item`, this.id)
      this.onCancel()
    },
    onCancel () {
      this.open = false
      this.id = ''
    }
  }
}
</script>

<style>

</style>
