package de.timkraut.consistec_programming_contest;

import org.junit.*;
import org.junit.runner.*;
import org.junit.runners.*;

import java.io.*;

/**
 * Tests the FileHandler class.
 *
 * @author Tim Kraut
 */
@RunWith(JUnit4.class)
public class FileHandlerTest {
    /**
     * Test if readFile() throws an ObjectNullException when given null as file name.
     */
    @Test(expected = ObjectNullException.class)
    public void testReadFileNull() throws Exception {
        FileHandler.readFile(null);
    }

    /**
     * Test if readFile() throws a StringEmptyException when given an empty string as file name.
     */
    @Test(expected = StringEmptyException.class)
    public void testReadFileEmptyString() throws Exception {
        FileHandler.readFile("");
    }

    /**
     * Test if readFile() throws a FileNotFoundException when given a non existing file name.
     */
    @Test(expected = FileNotFoundException.class)
    public void testReadFileNoValidFile() throws Exception {
        FileHandler.readFile("non_existing_file");
    }

    /**
     * Test if writeFile() throws an ObjectNullException when given null as content.
     */
    @Test(expected = ObjectNullException.class)
    public void testWriteFileContentNull() throws Exception {
        FileHandler.writeFile(null, "not null");
    }

    /**
     * Test if writeFile() throws a StringEmptyException when given an empty string as content.
     */
    @Test(expected = StringEmptyException.class)
    public void testWriteFileContentEmpty() throws Exception {
        FileHandler.writeFile("", "not empty");
    }

    /**
     * Test if writeFile() throws a StringEmptyException when given a string which has only whitespace characters as
     * content.
     */
    @Test(expected = StringEmptyException.class)
    public void testWriteFileContentEmptySpaces() throws Exception {
        FileHandler.writeFile("          ", "not empty");
    }

    /**
     * Test if writeFile() throws an ObjectNullException when given null as outputFileName.
     */
    @Test(expected = ObjectNullException.class)
    public void testWriteFileOutputFileNameNull() throws Exception {
        FileHandler.writeFile("not null", null);
    }

    /**
     * Test if writeFile() throws a StringEmptyException when given an empty string as outputFileName.
     */
    @Test(expected = StringEmptyException.class)
    public void testWriteFileOutputFileNameEmpty() throws Exception {
        FileHandler.writeFile("not empty", "");
    }

    /**
     * Test if writeFile() throws a StringEmptyException when given a string which has only whitespace characters as
     * outputFileName.
     */
    @Test(expected = StringEmptyException.class)
    public void testWriteFileOutputFileNameEmptySpaces() throws Exception {
        FileHandler.writeFile("not empty", "          ");
    }
}
