package de.timkraut.consistec_programming_contest;

import java.io.*;

/**
 * <p>Reads (multiple) input and output files and encodes every character.</p> <p>The encoding follows this
 * algorithm:</p> <p/> <h1>Upper case characters</h1>
 * <p><pre>
 * A   = ASCII value + 12
 * B-M = ASCII value - 1
 * N-Y = ASCII value + 1
 * Z   = ASCII value - 12
 * </pre></p>
 * <h1>Lower case characters</h1>
 * <p><pre>
 * a-k = ASCII value + 2
 * l-m = ASCII value - 11
 * n-o = ASCII value + 11
 * p-z = ASCII value - 2
 * </pre></p>
 *
 * @author Tim Kraut
 */
// TODO Refactor!!
public final class Encoder {
    // Error constants
    private static final String ERR_NO_INPUT_FILE           = "No input file name given.\n";
    private static final String ERR_NO_OUTPUT_FILE          = "No output file name given.\n";
    private static final String ERR_NOT_ENOUGH_OUTPUT_FILES = "Not enough file names given. Every input file name needs a output file name.\n";
    // Text constants
    private static final String START_INSTRUCTION           = "Start the encoder with: encoder [inputFile_1] [outputFile_1] [inputFile_2] [outputFile_2] ... ";
    private String[] inputFileNames;
    private String[] outputFileNames;

    /**
     * Prevent instantiating.
     */
    private Encoder(String[] fileNames) {
        // Split and save input and output file names
        setInputOutputFileNames(fileNames);
    }

    /**
     * Start the encoder with: encoder [inputFile_1] [outputFile_1] [inputFile_2] [outputFile_2] ...
     *
     * @param args Input and output file names.
     */
    public static void main(String[] args) {
        try {
            checkValidNumArguments(args.length);

            // Start encoding
            Encoder encoder = new Encoder(args);
            encoder.encode();
        } catch (MissingArgumentsException e) {
            System.err.println(e.getMessage());
            System.err.println(START_INSTRUCTION);

        } catch (ObjectNullException e) {
            //System.err.println(e);


        } catch (StringEmptyException e) {
            System.err.println(e.getMessage());


        } catch (FileNotFoundException e) {
            System.err.println(e.getMessage());


        } catch (FileNotRegularException e) {
            System.err.println(e.getMessage());


        } catch (FileNotReadableException e) {
            System.err.println(e.getMessage());


        } catch (IOException e) {
            //System.err.println(e);


        } catch (Exception e) {
            //System.err.println(e);

        }
    }

    /**
     * Throws an exception if the given num is < 2 or odd.
     *
     * @param num Number of arguments.
     *
     * @throws MissingArgumentsException No input file given.
     * @throws MissingArgumentsException No output file given.
     * @throws MissingArgumentsException Not enough output files. Every input file needs a corresponding output file.
     */

    private static void checkValidNumArguments(int num) throws MissingArgumentsException {
        // Check if input file name given
        if (num < 1) {
            throw new MissingArgumentsException(ERR_NO_INPUT_FILE);
        }

        // Check if output file name given
        if (num < 2) {
            throw new MissingArgumentsException(ERR_NO_OUTPUT_FILE);
        }

        // Check if number of arguments is even
        if (num % 2 != 0) {
            throw new MissingArgumentsException(ERR_NOT_ENOUGH_OUTPUT_FILES);
        }
    }

    /**
     * Writes input and output file names into their corresponding arrays.
     *
     * @param fileNames Array which contains the file names: [inputFile_1][outputFile_1][inputFile_2][outputFile_2] ...
     */
    private void setInputOutputFileNames(String[] fileNames) {
        // Dimension file name arrays
        int numFileNamePairs = fileNames.length / 2;
        inputFileNames = new String[numFileNamePairs];
        outputFileNames = new String[numFileNamePairs];

        // Track array positions
        int inputFilesPosition = 0;
        int outputFilesPosition = 0;

        for (int i = 0; i < fileNames.length; i++) {
            if (i % 2 == 0) {
                // Input file
                inputFileNames[inputFilesPosition] = fileNames[i];
                inputFilesPosition++;
            } else {
                // Output file
                outputFileNames[outputFilesPosition] = fileNames[i];
                outputFilesPosition++;
            }
        }
    }

    /**
     * Encodes every input/output file pair.
     *
     * @throws ObjectNullException      inputFileName is null.
     * @throws StringEmptyException     inputFileName is empty.
     * @throws FileNotFoundException    Given file name doesn't point to an existing file.
     * @throws FileNotRegularException  Given file name doesn't point to a regular file.
     * @throws FileNotReadableException Given file name doesn't point to a readable file.
     * @throws IOException
     */
    private void encode() throws ObjectNullException, StringEmptyException, FileNotFoundException, FileNotRegularException, FileNotReadableException, IOException {
        String fileContent;

        for (int i = 0; i < inputFileNames.length; i++) {
            fileContent = FileHandler.readFile(inputFileNames[i]);
            fileContent = ConsistecAlgorithm.encode(fileContent);
            FileHandler.writeFile(fileContent, outputFileNames[i]);
        }
    }

    /**
     * Encodes a given
     */
}
