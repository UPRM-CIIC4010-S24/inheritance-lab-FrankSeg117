#include "StarterCode.hpp"

/* Collectable Interface */
class Collectable {
  public:
    virtual int getCentury() = 0;

    virtual bool isSuccessful() = 0;

    virtual bool isLegit() = 0;
};

/* Exercise 6A
 * YOU MUST CHANGE THIS BELOW WITH YOUR CURRENT PAINTING CLASS
 * AND IMPLEMENT THE COLLECTABLE METHODS IN PAINTING AFTER THE
 * INHERITING
 */
class Painting : public Art, public Collectable{
    private:
    // string name;
    // Artist artist;
    // Style style;
    // int year;
    bool replica;

  public:
    // Null Constructor
    Painting(){};

    // Parameterized Constructor
    Painting(string name, Artist artist, Style style, int year, bool replica) : Art( name,  artist,  style, year){
        // this->name = name;
        // this->artist = artist;
        // this->style = style;
        // this->year = year;
        this->replica = replica;
    }

    // Getters
    // string getName() const { return name; }
    // Artist getArtist() const { return artist; }
    // Style getStyle() const { return this->style; }
    // int getYear() const { return year; }
    bool isReplica() const { return replica; }

    // Setters
    // void setName(string name) { this->name = name; }
    // void setArtist(Artist artist) { this->artist = artist; }
    // void setStyle(Style style) { this->style = style; }
    // void setYear(int year) { this->year = year; }
    void setReplica(bool isReplica) { this->replica = isReplica; }

    // Methods
    /*
     * Given a vector of Paintings, return the count of how many paintings
     * qualify with the given style and its year is between the given start
     * and end (inclusive).
     */
    static int countPaintings(const vector<Painting *> &collection, Style style, int start, int end);
    int appraise() {return 0;}

    int getCentury(){
      return (getYear()/100) + 1;
    }
    bool isSuccessful(){
      if(getArtist().getFameScore() > 7 && (getStyle().getDominantEra().first <= getYear() && getStyle().getDominantEra().second >= getYear())){
        return true;
      }
      return false;
    }
    bool isLegit(){
      return !isReplica();
    }
};

/* Exercise 6B
 * YOU MUST CHANGE THIS BELOW WITH YOUR CURRENT SCULPTURE CLASS
 * AND IMPLEMENT THE COLLECTABLE METHODS IN SCULPTURE AFTER THE
 * INHERITING
 */
class Sculpture : public Art, public Collectable{
  private:
    // string name;
    // Artist artist;
    // Style style;
    // int year;
    Material material;

  public:
    // Null Constructor
    Sculpture(){};

    // Parameterized Constructor
    Sculpture(string name, Artist artist, Style style, int year, Material material) : Art( name,  artist,  style,  year){
        // this->name = name;
        // this->artist = artist;
        // this->style = style;
        // this->year = year;
        this->material = material;
    }

    // Getters
    // string getName() const { return name; }
    // Artist getArtist() const { return artist; }
    // Style getStyle() const { return this->style; }
    // int getYear() const { return year; }
    Material getMaterial() const { return material; }

    // Setters
    // void setName(string name) { this->name = name; }
    // void setArtist(Artist artist) { this->artist = artist; }
    // void setStyle(Style style) { this->style = style; }
    // void setYear(int year) { this->year = year; }
    void setMaterial(Material material) { this->material = material; }

    // Methods
    /*
     * Given a vector of Art pieces, return a vector containing only the
     * Sculptures in the original vector. You must use dynamic casting to
     * determine whether an Art piece is a Sculpture or not .
     */
    static vector<Sculpture *> segregateSculptures(const vector<Art *> &collection);

    int appraise() {}

    int getCentury(){
      return (getYear()/100)+1;
    }
    bool isSuccessful(){
      if(getArtist().getFameScore()>5 && (getStyle().getDominantEra().first <= getYear() && getYear() < getStyle().getDominantEra().second)){
        return true;
      }
      return false;
    }
    bool isLegit(){
      return getMaterial() == MARBLE || getMaterial() == WAX || getMaterial() == METAL;
    }
};
