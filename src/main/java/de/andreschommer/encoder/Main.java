package de.andreschommer.encoder;

import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;


public class Main {
	
	private Encoder encoder;
	
	
	public Main() {
		encoder = new Encoder();
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Main main = new Main();
		if(args.length < 2) {
			System.err.println("Missing arguments");
			main.usage();
			System.exit(1);
		}
		Path inputFile = Paths.get(args[0]);
		Path outputFile = Paths.get(args[1]);
		try {
			main.encodeFile(inputFile, outputFile);
		} catch (IOException e) {
			System.err.println(e.toString());
//			e.printStackTrace();
			main.usage();
		}
	}
	
	/**
	 * Encodes the text in inputFile and prints the encoded text to the outputFile.
	 * The text has to be ASCII
	 * @param inputFile - path to the file to be encoded
	 * @param outputFile - path to the output file
	 * @throws IOException if an I/O error occurs writing or reading one of the files
	 */
	private void encodeFile(Path inputFile, Path outputFile) throws IOException {
		List<String> lines = Files.readAllLines(inputFile, Charset.forName("US-ASCII"));
		for(int i = 0; i < lines.size(); ++i) {
			lines.set(i, encoder.encode(lines.get(i)));
		}
		Files.write(outputFile, lines, Charset.forName("US-ASCII"));
	}
	
	/**
	 * Prints out the usage details
	 */
	private void usage() {
		System.out.println("Usage: java -jar encoder.jar inputfile outputfile");
	}

}
