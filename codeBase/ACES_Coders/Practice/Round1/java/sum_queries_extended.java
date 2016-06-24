import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.Reader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.InputStream;

class SumQueries {
    public static void main(String[] args){
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        int N=in.readInt();int Q=in.readInt();
        long[] ar=in.readLongArray(N);
        long[] cumilativeSum=new long[N+1];
        for(int x=1;x<=N;x++) cumilativeSum[x]=cumilativeSum[x-1]+ar[x-1];
        for(int x=0;x<Q;x++){
            int p=in.readInt();int q=in.readInt();
            out.printLine(cumilativeSum[q+1]-cumilativeSum[p]);           
        }
        out.close();
    }
}

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
    
        public long readLong() {
            return Long.parseLong(readWord());
        }

        public int[] readIntArray(int size) {
            int[] result = new int[size];
            for (int i = 0; i < size; i++) {
                result[i] = readInt();
            }
            return result;
        }
        
        public long[] readLongArray(int size) {
            long[] result = new long[size];
            for (int i = 0; i < size; i++) {
                result[i] = readLong();
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