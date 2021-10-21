import {Entity, Column, ManyToOne} from "typeorm";
import  Model  from './Model'
import { User } from "./User";

@Entity("posts")
export class Post extends Model{

    @Column()
    title: string;

    @Column()
    body: string;

    @ManyToOne(()=> User) //, user => user.posts to many to one thats optional
    user: User

}
