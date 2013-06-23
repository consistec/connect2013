package de.timkraut.consistec_programming_contest;

import java.io.*;
import static de.timkraut.consistec_programming_contest.ObjectNullException.*;
import static de.timkraut.consistec_programming_contest.StringEmptyException.*;

/**
 * Read and write files, check if they're valid.
 *
 * @author Tim Kraut
 */
public final class FileHandler {
    // Error constants
    private static final String ERR_FILE_NOT_EXISTING = " is not existing.\n";
    private static final String ERR_FILE_NOT_REGULAR  = " is not a regular file.\n";
    private static final String ERR_FILE_NOT_READABLE = " is not readable..\n";

    // Other constants
    private static final int    EOF                   = -1;

    /**
     * Prevent instantiating.
     */
    private FileHandler() {}

    /**
     * Throws an exception if the given file doesn't point to an existing file.
     *
     * @param file File to check.
     *
     * @throws java.io.FileNotFoundException File doesn't point to an existing file.
     */
    private static void checkExistingFile(File file) throws FileNotFoundException {
        if (!file.exists()) {
            throw new FileNotFoundException(file + ERR_FILE_NOT_EXISTING);
        }
    }

    /**
     * Throws an exception if the given file doesn't point to a regular file.
     *
     * @param file File to check.
     *
     * @throws FileNotRegularException File doesn't point to a regular file.
     */
    private static void checkRegularFile(File file) throws FileNotRegularException {
        if (!file.isFile()) {
            throw new FileNotRegularException(file + ERR_FILE_NOT_REGULAR);
        }
    }

    /**
     * Throws an exception if the given file doesn't point to a readable file.
     *
     * @param file File to check.
     *
     * @throws FileNotReadableException File doesn't point to a readable file.
     */
    private static void checkReadableFile(File file) throws FileNotReadableException {
        if (!file.canRead()) {
            throw new FileNotReadableException(file + ERR_FILE_NOT_READABLE);
        }
    }

    /**
     * Throws an exception if the file doesn't point to an existing, regular or readable file.
     *
     * @param file File to check.
     *
     * @throws FileNotFoundException    Given file doesn't point to an existing file.
     * @throws FileNotRegularException  Given file doesn't point to a regular file.
     * @throws FileNotReadableException Given file doesn't point to a readable file.
     */
    private static void checkValidFile(File file) throws FileNotFoundException, FileNotRegularException, FileNotReadableException {
        checkExistingFile(file);
        checkRegularFile(file);
        checkReadableFile(file);
    }

    /**
     * Reads the given file.
     *
     * @param inputFileName Name of the file to read.
     *
     * @return Content of the file.
     *
     * @throws ObjectNullException      inputFileName is null.
     * @throws StringEmptyException     inputFileName is empty.
     * @throws FileNotFoundException    Given file name doesn't point to an existing file.
     * @throws FileNotRegularException  Given file name doesn't point to a regular file.
     * @throws FileNotReadableException Given file name doesn't point to a readable file.
     * @throws IOException
     */
    public static String readFile(String inputFileName) throws ObjectNullException, StringEmptyException, FileNotFoundException, FileNotRegularException, FileNotReadableException, IOException {
        checkNotNull(inputFileName);
        checkStringNotEmpty(inputFileName);

        File inputFile = new File(inputFileName);
        checkValidFile(inputFile);

        return readFileContent(inputFile);
    }

    /**
     * Reads the content of the given file.
     *
     * @param file File to read.
     *
     * @return Content of the file.
     *
     * @throws IOException
     */
    private static String readFileContent(File file) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(file));
        StringBuilder stringBuilder = new StringBuilder();

        int curChar;

        // Read the content of the file
        while ((curChar = reader.read()) != EOF) {
            stringBuilder.append((char) curChar);
        }

        reader.close();

        return stringBuilder.toString();
    }

    /**
     * Writes the given content into a new file with the given file name.
     *
     * @param content        Content of the new file.
     * @param outputFileName Name of the new file.
     *
     * @throws ObjectNullException  content is null.
     * @throws StringEmptyException content is empty.
     * @throws ObjectNullException  outputFileName is null.
     * @throws StringEmptyException outputFileName is empty.
     * @throws IOException
     */
    public static void writeFile(String content, String outputFileName) throws ObjectNullException, StringEmptyException, IOException {
        checkNotNull(content);
        checkStringNotEmpty(content);

        checkNotNull(outputFileName);
        checkStringNotEmpty(outputFileName);

        File outputFile = new File(outputFileName);
        writeFileContent(content, outputFile);
    }

    /**
     * Writes the given content to the given file.
     *
     * @param content Content of the new file.
     * @param file    New file.
     *
     * @throws IOException
     */
    private static void writeFileContent(String content, File file) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(file));

        writer.write(content);

        writer.close();
    }
}
