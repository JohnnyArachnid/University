package org.starmap.utils;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.io.TempDir;
import org.starmap.controller.StarMapController;
import org.starmap.model.Constellation;
import org.starmap.model.Star;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

public class DataWriterTest {

    @TempDir
    Path tempDir;
    private Path testFilePath;

    @BeforeEach
    void setUp() throws IOException {
        testFilePath = tempDir.resolve("test.json");
        String testJson = """
                {
                  "stars": [
                    {
                      "name": "Sirius",
                      "xPosition": 100,
                      "yPosition": 200,
                      "brightness": 1.46
                    },
                    {
                      "name": "Canopus",
                      "xPosition": 150,
                      "yPosition": 250,
                      "brightness": 0.72
                    },
                    {
                      "name": "Aldebaran",
                      "xPosition": 50,
                      "yPosition": 400,
                      "brightness": 0.85
                    },
                    {
                      "name": "Elnath",
                      "xPosition": 100,
                      "yPosition": 450,
                      "brightness": 1.65
                    }
                  ],
                  "constellations": [
                    {
                      "name": "Taurus",
                      "stars": [
                        "Aldebaran",
                        "Elnath"
                      ]
                    }
                  ]
                }""";
        Files.writeString(testFilePath, testJson);
    }

    @Test
    void testWriteStars() {
        List<Star> stars = DataLoader.loadStars(testFilePath.toString());
        List<Constellation> constellations = DataLoader.loadConstellations(testFilePath.toString(), stars);
        StarMapController controller = new StarMapController(stars,constellations);
        DataWriter.writeFile("src/main/resources/tests.json",controller);
        List<Star> testStars = DataLoader.loadStars("src/main/resources/tests.json");
        assertEquals(4, testStars.size());
        assertTrue(testStars.stream().anyMatch(star -> star.getName().equals("Sirius")));
        assertTrue(testStars.stream().anyMatch(star -> star.getName().equals("Canopus")));
    }

    @Test
    void testLoadConstellations() {
        List<Star> stars = DataLoader.loadStars(testFilePath.toString());
        List<Constellation> constellations = DataLoader.loadConstellations(testFilePath.toString(), stars);
        StarMapController controller = new StarMapController(stars,constellations);
        DataWriter.writeFile("src/main/resources/tests.json",controller);
        List<Star> testStars = DataLoader.loadStars("src/main/resources/tests.json");
        List<Constellation> testConstellation = DataLoader.loadConstellations("src/main/resources/tests.json", testStars);

        assertEquals(1, testConstellation.size());
        Constellation taurus = testConstellation.get(0);
        assertEquals("Taurus", taurus.getName());
        assertEquals(2, taurus.getStars().size());
        assertTrue(taurus.getStars().stream().anyMatch(star -> star.getName().equals("Aldebaran")));
        assertTrue(taurus.getStars().stream().anyMatch(star -> star.getName().equals("Elnath")));
    }
}

