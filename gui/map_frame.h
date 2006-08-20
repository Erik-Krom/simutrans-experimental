/*
 * map_frame.h
 *
 * Copyright (c) 1997 - 2001 Hansj�rg Malthaner
 *
 * This file is part of the Simutrans project and may not be used
 * in other projects without written permission of the author.
 */

/*
 * [Mathew Hounsell] Min Size Button On Map Window 20030313
 */

#include "gui_frame.h"
#include "gui_scrollpane.h"
#include "ifc/action_listener.h"
#include "button.h"
#include "karte.h"

class karte_modell_t;

/**
 * Reliefkartenfenster f�r Simutrans.
 *
 * @author Hj. Malthaner
 * @date 03-Mar-01
 * @version $Revision: 1.11 $
 */
class map_frame_t : public gui_frame_t
{
private:

  /**
   * This is kind of hack: we know there can only be one map frame
   * at atime,and we want to save the current size for the next object
   * so we use a static variable here.
   * @author Hj. Malthaner
   */
  static koord size;

  static koord screenpos;

  /**
   * We need to keep track of trag/click events
   * @author Hj. Malthaner
   */
  bool is_dragging;


  gui_scrollpane_t scrolly;


public:

    /**
     * Manche Fenster haben einen Hilfetext assoziiert.
     * @return den Dateinamen f�r die Hilfe, oder NULL
     * @author Hj. Malthaner
     */
    virtual const char * gib_hilfe_datei() const {return "map.txt";};


    /**
     * Does this window need a min size button in the title bar?
     * @return true if such a button is needed
     * @author Hj. Malthaner
     */
    virtual bool has_min_sizer() const {return true;};


    /**
     * Konstruktor. Erzeugt alle notwendigen Subkomponenten.
     * @author Hj. Malthaner
     */
    map_frame_t(const karte_modell_t *welt);

	// destructor needed for closing mapwindow legend
	virtual ~map_frame_t();

    /**
     * Events werden hiermit an die GUI-Komponenten
     * gemeldet
     * @author Hj. Malthaner
     */
    virtual void infowin_event(const event_t *ev);


    /**
     * Setzt die Fenstergroesse
     * @author (Mathew Hounsell)
     * @date   11-Mar-2003
     */
    virtual void setze_fenstergroesse(koord groesse);

    /**
     * resize window in response to a resize event
     * @author Hj. Malthaner
     * @date   01-Jun-2002
     */
    virtual void resize(const koord delta);


    /**
     * komponente neu zeichnen. Die �bergebenen Werte beziehen sich auf
     * das Fenster, d.h. es sind die Bildschirkoordinaten des Fensters
     * in dem die Komponente dargestellt wird.
     * @author Hj. Malthaner
     */
    virtual void zeichnen(koord pos, koord gr);

};
