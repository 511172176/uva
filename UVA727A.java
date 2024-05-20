import java.util.*;

/**
 * UVA727A
 */
public class UVA727A {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();

        while(n-->0){
            Stack<String> st = new Stack<>();
            String stt = "";
            boolean firstline = true;

            while(sc.hasNextLine()){
                String s = sc.nextLine();
                if(s.isEmpty()){
                    if(!firstline) break;
                    continue;
                }
                firstline = false;

                if(Character.isDigit(s.charAt(0))){
                    stt += s;
                }
                else{
                    if(s.equals("("))
                        st.push(s);
                    else if(s.equals(")")){
                        while(!st.empty() && !st.peek().equals("(")){
                            stt += st.pop();
                        }
                        st.pop();
                    }
                    else if(s.equals("*") || s.equals("/")){
                        while(!st.empty() && (st.peek().equals("*") || st.peek().equals("/"))){
                            stt += st.pop();
                        }
                        st.push(s);
                    }
                    else if(s.equals("+") || s.equals("-")){
                        while(!st.empty() && (st.peek().equals("*") || st.peek().equals("/")
                            || st.peek().equals("+") || st.peek().equals("-"))){
                            stt += (st.pop());
                        }
                        st.push(s);
                    }
                }
            }
            while(!st.empty()){
                    stt += (st.pop());
            }
            System.out.println(stt);
            if(n>0)
                System.out.println();
        }
        sc.close();
    }
}