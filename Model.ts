import { BaseEntity, BeforeInsert, Column, CreateDateColumn, PrimaryGeneratedColumn, UpdateDateColumn } from "typeorm";
import { v4 } from 'uuid'

export default abstract class Model extends BaseEntity{

  @PrimaryGeneratedColumn()
  id: number;
  

  @Column({type: 'uuid'})
    uuid: string

    @CreateDateColumn()
    createdAt: Date

    @UpdateDateColumn()
    updatedAt: Date

    @BeforeInsert() //Is called Listener, lifecycle Events
    createUuid(){
      this.uuid = v4() 
    }

    toJSON(){ //removing the id from the response, as we dont want it to be exposed
      return { ...this,id: undefined} // this refers to THis instance
    }

    constructor(model?: Partial<any>){
      super()
      Object.assign(this, model)
    }
}
