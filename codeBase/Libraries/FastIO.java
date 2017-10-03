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
/*
*DESCRIPTION:
When handling extremely large input or output in Java, the slowness of the Scanner can be a cause for timeout in Programming Contests. These two classes InputReader
and OutputWriter provide extremely fast IO with the use of BufferedReader and StringTokenizer classes.

*USING THIS CODE:
InputStream inputStream = System.in;
OutputStream outputStream = System.out;
InputReader in = new InputReader(inputStream);
OutputWriter out = new OutputWriter(outputStream);
int n = in.readInt();
int[] a = in.readIntArray(n);
out.printLine(n);
*/

import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.Reader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(Reader reader) {
        this.reader = new BufferedReader(reader);
    }

    public InputReader(InputStream stream) {
        this(new InputStreamReader(stream));
    }

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public String readWord() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(nextLine());
        }
        return tokenizer.nextToken();
    }

    public int readInt() {
        return Integer.parseInt(readWord());
    }

    public int[] readIntArray(int size) {
        int[] result = new int[size];
        for (int i = 0; i < size; i++) {
            result[i] = readInt();
        }
        return result;
    }

}

class OutputWriter {
    private PrintWriter writer;

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public OutputWriter(OutputStream stream) {
        this(new OutputStreamWriter(stream));
    }

    public void print(Object... args) {
        for (Object arg : args) {
            writer.print(arg);
        }
    }

    public void printLine(Object... args) {
        print(args);
        writer.println();
    }

    void close() {
        writer.close();
    }

}