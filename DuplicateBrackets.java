// Given a string exp representing an expression.
// Assume that the expression is balanced  i.e. the opening and closing brackets match with each other.
// But, some of the pair of brackets maybe extra/needless. 
// Print true if there exists extra brackets and false otherwise.

// Examples -  (a + b) + ((c + d)) -> true    ,     ((a + b) + (c + d)) -> false

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        
        Scanner scn=new Scanner(System.in);
        
        String str=scn.nextLine();
        
        Stack<Character> st=new Stack<>();
        
        // loop over the entire expression
        for(int i=0;i<str.length();i++){
            
            char ch=str.charAt(i);
            
            if(ch==')'){ // If the current character is a closing bracket i.e ')'
                if(st.peek()=='('){  // if there are no numbers between the opening and closing bracket , i.e no use of this bracket , duplicacy found
                    System.out.println(true);  // print true and return
                    return;
                }else{  // if there are number and expression between closing and opening bracket i.e the bracket is of use
                    while(st.peek()!='('){   // pop until you find an opening bracket , pop the opening bracket also
                        st.pop();
                    }
                    st.pop();
                }
            }
          else{     // If current character is a opening brakcet i.e '(' or any number expression , simply push on the stack
                st.push(ch);
            }
            
            
        }
        
        System.out.println(false); // at last print false as no duplicate brackets found otherwise would have returned from the function earlier
        
    }

}
