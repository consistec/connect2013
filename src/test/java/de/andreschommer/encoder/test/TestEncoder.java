package de.andreschommer.encoder.test;


import static org.hamcrest.CoreMatchers.is;
import static org.junit.Assert.assertThat;
import org.testng.annotations.BeforeTest;
import org.testng.annotations.Test;
import de.andreschommer.encoder.Encoder;

public class TestEncoder {
	
	private Encoder encoder;
	
	@BeforeTest
	public void setUp() {
		encoder = new Encoder();
	}

	@Test
	public void testEncode() {
		assertThat(encoder.encode("abc"), is("cde"));
		assertThat(encoder.encode("abcklmnopxyz"), is("cdemabyznvwx"));
		String inputText =
				"Wir wollen Euch testen und sind sehr gespannt auf die Antworten. Hoffentlich sind es mehr als 2. Zeigt uns, dass Ihr es drauf habt! Also mehr Hilfe wollen wir Euch nicht geben.";
		String outputText =
				"Xkp uzaagy Dsej rgqrgy syf qkyf qgjp igqncyyr csh fkg Myruzprgy. Gzhhgyrakej qkyf gq bgjp caq 2. Ngkir syq, fcqq Hjp gq fpcsh jcdr! Maqz bgjp Gkahg uzaagy ukp Dsej ykejr igdgy.";
		assertThat(encoder.encode(inputText), is(outputText));
	}
	
	@Test
	public void testEncodeLowercaseLetters() {
		assertThat(encoder.encode("abcdefghijklmnopqrstuvwxyz"), is("cdefghijklmabyznopqrstuvwx"));
	}
	
	@Test
	public void testEncodeUppercaseLetters() {
		assertThat(encoder.encode("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), is("MABCDEFGHIJKLOPQRSTUVWXYZN"));
	}

	@Test
	public void testEncodeWithSpecialCharacters() {
		assertThat(encoder.encode("!\"§$%&/()=?\\*+'#-_:.;,<>|^°0123456789"), is("!\"§$%&/()=?\\*+'#-_:.;,<>|^°0123456789"));
	}
}
