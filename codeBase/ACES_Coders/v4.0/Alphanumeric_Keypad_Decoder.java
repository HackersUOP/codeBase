/*
Copyright Hackers' Club, University Of Peradeniya
Author : E/13/181 (Samurdhi Karunarathne)
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at *
http://www.apache.org/licenses/LICENSE-2.0 *
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    static Map<Character, String> map;
    static String[] nums;
    static List<String> words;
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        words = new ArrayList<String>();
        String st = inp.next();
        while (!st.equals("#")) {
            words.add(st);
            st = inp.next();
        }
        String strng = inp.next();
        strng = "@00".concat(strng);
        String[] arr = strng.split("0+");
        arr = Arrays.copyOfRange(arr, 1, arr.length);
        nums = new String[words.size()];
        map = new HashMap<Character, String>();
        map.put('a', "2");
        map.put('b', "2");
        map.put('c', "2");
        map.put('d', "3");
        map.put('e', "3");
        map.put('f', "3");
        map.put('g', "4");
        map.put('h', "4");
        map.put('i', "4");
        map.put('j', "5");
        map.put('k', "5");
        map.put('l', "5");
        map.put('m', "6");
        map.put('n', "6");
        map.put('o', "6");
        map.put('p', "7");
        map.put('q', "7");
        map.put('r', "7");
        map.put('s', "7");
        map.put('t', "8");
        map.put('u', "8");
        map.put('v', "8");
        map.put('w', "9");
        map.put('x', "9");
        map.put('y', "9");
        map.put('z', "9");

        int l1 = words.size();
        for (int j = 0; j < l1; j++) {
            nums[j] = cnums(words.get(j));
        }
        for (int k = 0; k < arr.length; k++) {
            System.out.print(gen(arr[k]).concat(" "));
        }
    }
    public static String cnums(String a) {
        int l = a.length();
        String ret = "";
        for (int i = 0; i < l; i++) {
            Character c1 = Character.valueOf(a.charAt(i));
            ret = ret.concat(map.get(c1));
        }
        return ret;
    }
    public static String gen(String b) {
        int n = nums.length;
        List<String> arr = new ArrayList<String>();
        for (int i = 0; i < n; i++) {
            if (nums[i].equals(b)) {
                arr.add(words.get(i));
            }
        }
        int d = arr.size();
        if (d == 1) {
            return arr.get(0);
        } else if (d == 0) {
            String g = "";
            for (int h = 0; h < b.length(); h++) {
                g = g.concat("*");
            }
            return g;
        } else {
            String r = arr.get(0);
            for (int j = 1; j < d; j++) {
                r = r.concat("|").concat(arr.get(j));
            }
            return "[".concat(r).concat("]");
        }
    }
}