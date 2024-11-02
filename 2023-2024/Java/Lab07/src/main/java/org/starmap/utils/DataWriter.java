package org.starmap.utils;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import org.starmap.controller.StarMapController;
import org.starmap.model.Constellation;
import org.starmap.model.Star;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class DataWriter {
    public static void writeFile(String filePath, StarMapController controller) {
        if (filePath != null) {
            Gson gson = new GsonBuilder().setPrettyPrinting().create();
            try (FileWriter writer = new FileWriter(filePath)) {
                String starsJson = gson.toJson(controller.getStars());
                writer.write("{\n  \"stars\": " + starsJson + ",");
                writer.write("\n  \"constellations\": [");
                for (int i = 0; i < controller.getConstellations().size(); i++) {
                    Constellation constellation = controller.getConstellations().get(i);
                    writer.write("\n{ \"name\": \"" + constellation.getName() + "\", \n\"stars\": [");
                    List<String> starNames = new ArrayList<>();
                    for (int j = 0; j < constellation.getStars().size(); j++) {
                        starNames.add("\n \"" + constellation.getStars().get(j).getName() + "\"");
                    }
                    String starNamesJson = String.join(",", starNames);
                    writer.write(starNamesJson);
                    writer.write("]\n}");
                    if (i < controller.getConstellations().size() - 1) {
                        writer.write(",");
                    }
                }
                writer.write("\n]\n}");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
