/*****************************************************************************\
 *                        ANALYSIS PERFORMANCE TOOLS                         *
 *                                  wxparaver                                *
 *              Paraver Trace Visualization and Analysis Tool                *
 *****************************************************************************
 *     ___     This library is free software; you can redistribute it and/or *
 *    /  __         modify it under the terms of the GNU LGPL as published   *
 *   /  /  _____    by the Free Software Foundation; either version 2.1      *
 *  /  /  /     \   of the License, or (at your option) any later version.   *
 * (  (  ( B S C )                                                           *
 *  \  \  \_____/   This library is distributed in hope that it will be      *
 *   \  \__         useful but WITHOUT ANY WARRANTY; without even the        *
 *    \___          implied warranty of MERCHANTABILITY or FITNESS FOR A     *
 *                  PARTICULAR PURPOSE. See the GNU LGPL for more details.   *
 *                                                                           *
 * You should have received a copy of the GNU Lesser General Public License  *
 * along with this library; if not, write to the Free Software Foundation,   *
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA          *
 * The GNU LEsser General Public License is contained in the file COPYING.   *
 *                                 ---------                                 *
 *   Barcelona Supercomputing Center - Centro Nacional de Supercomputacion   *
\*****************************************************************************/

#ifndef _GTIMELINE_H_
#define _GTIMELINE_H_


/*!
 * Includes
 */
 #include <boost/date_time/posix_time/posix_time.hpp>

#include <wx/progdlg.h>
#include "prvtypes.h"

#ifdef _MSC_VER
#include <hash_set>
#else
#include <ext/hash_set>
#endif

#ifdef _MSC_VER
using namespace stdext;
#else
using namespace __gnu_cxx;
#endif

using boost::posix_time::ptime;

////@begin includes
#include "wx/frame.h"
#include "wx/splitter.h"
#include "wx/notebook.h"
#include "wx/richtext/richtextctrl.h"
////@end includes
#include <wx/treebase.h>

#include "wx/checkbox.h"
#include "wx/choicdlg.h"
#include "wx/dcmemory.h"
#include "wx/scrolwin.h"
#include "wx/timer.h"
#include "wx/icon.h"
#include "wx/slider.h"

#include "paraverkerneltypes.h"
#include "recordlist.h"
#include "popupmenu.h"
#include "copypaste.h"
#include "windows_tree.h"

#include "saveimagedialog.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxSplitterWindow;
class wxNotebook;
class wxRichTextCtrl;
class wxBoxSizer;
////@end forward declarations
class Window;
class ProgressController;


/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_GTIMELINE 10001
#define ID_SPLITTER_TIMELINE 10048
#define ID_SCROLLED_DRAW 10007
#define ID_NOTEBOOK_INFO 10042
#define ID_SCROLLED_WHATWHERE 10076
#define ID_CHECKBOX 10077
#define ID_CHECKBOX1 10079
#define ID_CHECKBOX2 10080
#define ID_CHECKBOX3 10083
#define ID_CHECKBOX4 10084
#define ID_CHECKBOX5 10004
#define ID_CHECKBOX6 10005
#define ID_RICHTEXTCTRL 10043
#define ID_SCROLLED_TIMING 10044
#define ID_TEXTCTRL_INITIALTIME 10045
#define wxID_STATIC_INITIALSEMANTIC 10288
#define ID_TEXTCTRL_INITIALSEMANTIC 10000
#define ID_TEXTCTRL_FINALTIME 10046
#define wxID_STATIC_FINALSEMANTIC 10289
#define ID_TEXTCTRL_FINALSEMANTIC 10002
#define ID_TEXTCTRL_DURATION 10047
#define wxID_STATIC_SLOPE 10290
#define ID_TEXTCTRL_SLOPE 10003
#define ID_SCROLLEDWINDOW 10008
#define ID_CHECKBOX_CUSTOM_PALETTE 10606
#define ID_BUTTON_CUSTOM_PALETTE_APPLY 10006
#define ID_SCROLLED_COLORS 10049
#define ID_PANEL 10009
#define wxID_STATIC1 10295
#define ID_SLIDER0 10010
#define wxID_STATIC2 10293
#define ID_SLIDER1 10011
#define wxID_STATIC3 10294
#define ID_SLIDER2 10012
#define SYMBOL_GTIMELINE_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxMAXIMIZE_BOX|wxCLOSE_BOX|wxFRAME_NO_TASKBAR|wxWANTS_CHARS|wxFULL_REPAINT_ON_RESIZE
#define SYMBOL_GTIMELINE_TITLE _("gTimeline")
#define SYMBOL_GTIMELINE_IDNAME ID_GTIMELINE
#define SYMBOL_GTIMELINE_SIZE wxSize(400, 300)
#define SYMBOL_GTIMELINE_POSITION wxDefaultPosition
////@end control identifiers
#define DEFAULT_IMAGE_DIALOG 1

#define ID_TIMER_SIZE 40000
#define ID_TIMER_MOTION 40001
#define ID_TIMER_WHEEL 40002


/*!
 * gTimeline class declaration
 */
class gTimeline: public wxFrame, public gWindow
{
  DECLARE_CLASS( gTimeline )
  DECLARE_EVENT_TABLE()

public:
  /// Constructors
  gTimeline();
  gTimeline( wxWindow* parent, wxWindowID id = SYMBOL_GTIMELINE_IDNAME, const wxString& caption = SYMBOL_GTIMELINE_TITLE, const wxPoint& pos = SYMBOL_GTIMELINE_POSITION, const wxSize& size = SYMBOL_GTIMELINE_SIZE, long style = SYMBOL_GTIMELINE_STYLE );

  bool Create( wxWindow* parent, wxWindowID id = SYMBOL_GTIMELINE_IDNAME, const wxString& caption = SYMBOL_GTIMELINE_TITLE, const wxPoint& pos = SYMBOL_GTIMELINE_POSITION, const wxSize& size = SYMBOL_GTIMELINE_SIZE, long style = SYMBOL_GTIMELINE_STYLE );

  /// Destructor
  ~gTimeline();

  /// Initialises member variables
  void Init();

  /// Creates the controls and sizers
  void CreateControls();

////@begin gTimeline event handler declarations

  /// wxEVT_CLOSE_WINDOW event handler for ID_GTIMELINE
  void OnCloseWindow( wxCloseEvent& event );

  /// wxEVT_IDLE event handler for ID_GTIMELINE
  void OnIdle( wxIdleEvent& event );

  /// wxEVT_RIGHT_DOWN event handler for ID_GTIMELINE
  void OnRightDown( wxMouseEvent& event );

  /// wxEVT_COMMAND_SPLITTER_DOUBLECLICKED event handler for ID_SPLITTER_TIMELINE
  void OnSplitterTimelineSashDClick( wxSplitterEvent& event );

  /// wxEVT_COMMAND_SPLITTER_UNSPLIT event handler for ID_SPLITTER_TIMELINE
  void OnSplitterTimelineSashUnsplit( wxSplitterEvent& event );

  /// wxEVT_SIZE event handler for ID_SCROLLED_DRAW
  void OnScrolledWindowSize( wxSizeEvent& event );

  /// wxEVT_PAINT event handler for ID_SCROLLED_DRAW
  void OnScrolledWindowPaint( wxPaintEvent& event );

  /// wxEVT_KEY_DOWN event handler for ID_SCROLLED_DRAW
  void OnScrolledWindowKeyDown( wxKeyEvent& event );

  /// wxEVT_UPDATE_UI event handler for ID_SCROLLED_DRAW
  void OnScrolledWindowUpdate( wxUpdateUIEvent& event );

  /// wxEVT_ERASE_BACKGROUND event handler for ID_SCROLLED_DRAW
  void OnScrolledWindowEraseBackground( wxEraseEvent& event );

  /// wxEVT_LEFT_DOWN event handler for ID_SCROLLED_DRAW
  void OnScrolledWindowLeftDown( wxMouseEvent& event );

  /// wxEVT_LEFT_UP event handler for ID_SCROLLED_DRAW
  void OnScrolledWindowLeftUp( wxMouseEvent& event );

  /// wxEVT_LEFT_DCLICK event handler for ID_SCROLLED_DRAW
  void OnScrolledWindowLeftDClick( wxMouseEvent& event );

  /// wxEVT_MIDDLE_UP event handler for ID_SCROLLED_DRAW
  void OnScrolledWindowMiddleUp( wxMouseEvent& event );

  /// wxEVT_RIGHT_DOWN event handler for ID_SCROLLED_DRAW
  void OnScrolledWindowRightDown( wxMouseEvent& event );

  /// wxEVT_MOTION event handler for ID_SCROLLED_DRAW
  void OnScrolledWindowMotion( wxMouseEvent& event );

  /// wxEVT_MOUSEWHEEL event handler for ID_SCROLLED_DRAW
  void OnScrolledWindowMouseWheel( wxMouseEvent& event );

  /// wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING event handler for ID_NOTEBOOK_INFO
  void OnNotebookInfoPageChanging( wxNotebookEvent& event );

  /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX
  void OnCheckWhatWhere( wxCommandEvent& event );

  /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX4
  void OnCheckWhatWhereText( wxCommandEvent& event );

  /// wxEVT_UPDATE_UI event handler for wxID_STATIC_SLOPE
  void OnStaticSlopeUpdate( wxUpdateUIEvent& event );

  /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX_CUSTOM_PALETTE
  void OnCheckboxCustomPaletteClick( wxCommandEvent& event );

  /// wxEVT_UPDATE_UI event handler for ID_CHECKBOX_CUSTOM_PALETTE
  void OnCheckboxCustomPaletteUpdate( wxUpdateUIEvent& event );

  /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_CUSTOM_PALETTE_APPLY
  void OnButtonCustomPaletteApplyClick( wxCommandEvent& event );

  /// wxEVT_UPDATE_UI event handler for ID_BUTTON_CUSTOM_PALETTE_APPLY
  void OnButtonCustomPaletteApplyUpdate( wxUpdateUIEvent& event );

  /// wxEVT_UPDATE_UI event handler for ID_SCROLLED_COLORS
  void OnScrolledColorsUpdate( wxUpdateUIEvent& event );

  /// wxEVT_UPDATE_UI event handler for wxID_STATIC1
  void OnStaticSelectedColorUpdate( wxUpdateUIEvent& event );

  /// wxEVT_COMMAND_SLIDER_UPDATED event handler for ID_SLIDER0
  void OnSliderSelectedColorUpdated( wxCommandEvent& event );

  /// wxEVT_UPDATE_UI event handler for ID_SLIDER0
  void OnSliderSelectedColorUpdateUI( wxUpdateUIEvent& event );

////@end gTimeline event handler declarations

  void MousePanMotion();
  void MousePanLeftUp( wxMouseEvent& event );
  
////@begin gTimeline member function declarations

  wxColour GetBackgroundColour() const { return backgroundColour ; }
  void SetBackgroundColour(wxColour value) { backgroundColour = value ; }

  long GetBeginRow() const { return beginRow ; }
  void SetBeginRow(long value) { beginRow = value ; }

  wxBitmap GetBufferImage() const { return bufferImage ; }
  void SetBufferImage(wxBitmap value) { bufferImage = value ; }

  bool GetCanRedraw() const { return canRedraw ; }
  void SetCanRedraw(bool value) { canRedraw = value ; }

  wxBitmap GetCommImage() const { return commImage ; }
  void SetCommImage(wxBitmap value) { commImage = value ; }

  bool GetDrawCaution() const { return drawCaution ; }
  void SetDrawCaution(bool value) { drawCaution = value ; }

  bool GetDrawCautionNegatives() const { return drawCautionNegatives ; }
  void SetDrawCautionNegatives(bool value) { drawCautionNegatives = value ; }

  wxBitmap GetDrawImage() const { return drawImage ; }
  void SetDrawImage(wxBitmap value) { drawImage = value ; }

  long GetEndRow() const { return endRow ; }
  void SetEndRow(long value) { endRow = value ; }

  bool GetEscapePressed() const { return escapePressed ; }
  void SetEscapePressed(bool value) { escapePressed = value ; }

  wxBitmap GetEventImage() const { return eventImage ; }
  void SetEventImage(wxBitmap value) { eventImage = value ; }

  TRecordTime GetFindBeginTime() const { return findBeginTime ; }
  void SetFindBeginTime(TRecordTime value) { findBeginTime = value ; }

  TRecordTime GetFindEndTime() const { return findEndTime ; }
  void SetFindEndTime(TRecordTime value) { findEndTime = value ; }

  TObjectOrder GetFindFirstObject() const { return findFirstObject ; }
  void SetFindFirstObject(TObjectOrder value) { findFirstObject = value ; }

  TObjectOrder GetFindLastObject() const { return findLastObject ; }
  void SetFindLastObject(TObjectOrder value) { findLastObject = value ; }

  wxMouseEvent GetFirstMotionEvent() const { return firstMotionEvent ; }
  void SetFirstMotionEvent(wxMouseEvent value) { firstMotionEvent = value ; }

  bool GetFirstUnsplit() const { return firstUnsplit ; }
  void SetFirstUnsplit(bool value) { firstUnsplit = value ; }

  wxColour GetForegroundColour() const { return foregroundColour ; }
  void SetForegroundColour(wxColour value) { foregroundColour = value ; }

  int GetInfoZoneLastSize() const { return infoZoneLastSize ; }
  void SetInfoZoneLastSize(int value) { infoZoneLastSize = value ; }

  TRecordTime GetLastEventFoundTime() const { return lastEventFoundTime ; }
  void SetLastEventFoundTime(TRecordTime value) { lastEventFoundTime = value ; }

  TObjectOrder GetLastFoundObject() const { return lastFoundObject ; }
  void SetLastFoundObject(TObjectOrder value) { lastFoundObject = value ; }

  TRecordTime GetLastSemanticFoundTime() const { return lastSemanticFoundTime ; }
  void SetLastSemanticFoundTime(TRecordTime value) { lastSemanticFoundTime = value ; }

  wxColour GetLogicalColour() const { return logicalColour ; }
  void SetLogicalColour(wxColour value) { logicalColour = value ; }

  wxPen GetLogicalPen() const { return logicalPen ; }
  void SetLogicalPen(wxPen value) { logicalPen = value ; }

  wxMouseEvent GetMotionEvent() const { return motionEvent ; }
  void SetMotionEvent(wxMouseEvent value) { motionEvent = value ; }

  Window* GetMyWindow() const { return myWindow ; }
  void SetMyWindow(Window* value) { myWindow = value ; }

  PRV_INT32 GetObjectAxisPos() const { return objectAxisPos ; }
  void SetObjectAxisPos(PRV_INT32 value) { objectAxisPos = value ; }

  wxFont GetObjectFont() const { return objectFont ; }
  void SetObjectFont(wxFont value) { objectFont = value ; }

  int GetObjectHeight() const { return objectHeight ; }
  void SetObjectHeight(int value) { objectHeight = value ; }

  vector<PRV_INT32> GetObjectPosList() const { return objectPosList ; }
  void SetObjectPosList(vector<PRV_INT32> value) { objectPosList = value ; }

  wxColour GetPhysicalColour() const { return physicalColour ; }
  void SetPhysicalColour(wxColour value) { physicalColour = value ; }

  wxPen GetPhysicalPen() const { return physicalPen ; }
  void SetPhysicalPen(wxPen value) { physicalPen = value ; }

  bool GetRedoColors() const { return redoColors ; }
  void SetRedoColors(bool value) { redoColors = value ; }

  wxStopWatch * GetRedrawStopWatch() const { return redrawStopWatch ; }
  void SetRedrawStopWatch(wxStopWatch * value) { redrawStopWatch = value ; }

  std::map< rgb, std::set<TSemanticValue> > GetSemanticColorsToValue() const { return semanticColorsToValue ; }
  void SetSemanticColorsToValue(std::map< rgb, std::set<TSemanticValue> > value) { semanticColorsToValue = value ; }

  wxFont GetSemanticFont() const { return semanticFont ; }
  void SetSemanticFont(wxFont value) { semanticFont = value ; }

  std::map< int, std::set<TSemanticValue> >  GetSemanticPixelsToValue() const { return semanticPixelsToValue ; }
  void SetSemanticPixelsToValue(std::map< int, std::set<TSemanticValue> >  value) { semanticPixelsToValue = value ; }

  std::map< TSemanticValue, rgb > GetSemanticValuesToColor() const { return semanticValuesToColor ; }
  void SetSemanticValuesToColor(std::map< TSemanticValue, rgb > value) { semanticValuesToColor = value ; }

  bool GetSplitChanged() const { return splitChanged ; }
  void SetSplitChanged(bool value) { splitChanged = value ; }

  PRV_INT32 GetTimeAxisPos() const { return timeAxisPos ; }
  void SetTimeAxisPos(PRV_INT32 value) { timeAxisPos = value ; }

  wxFont GetTimeFont() const { return timeFont ; }
  void SetTimeFont(wxFont value) { timeFont = value ; }

  wxTimer * GetTimerMotion() const { return timerMotion ; }
  void SetTimerMotion(wxTimer * value) { timerMotion = value ; }

  wxTimer * GetTimerSize() const { return timerSize ; }
  void SetTimerSize(wxTimer * value) { timerSize = value ; }

  wxTimer * GetTimerWheel() const { return timerWheel ; }
  void SetTimerWheel(wxTimer * value) { timerWheel = value ; }

  bool GetTiming() const { return timing ; }
  void SetTiming(bool value) { timing = value ; }

  TObjectOrder GetWheelZoomBeginObject() const { return wheelZoomBeginObject ; }
  void SetWheelZoomBeginObject(TObjectOrder value) { wheelZoomBeginObject = value ; }

  TRecordTime GetWheelZoomBeginTime() const { return wheelZoomBeginTime ; }
  void SetWheelZoomBeginTime(TRecordTime value) { wheelZoomBeginTime = value ; }

  TObjectOrder GetWheelZoomEndObject() const { return wheelZoomEndObject ; }
  void SetWheelZoomEndObject(TObjectOrder value) { wheelZoomEndObject = value ; }

  TRecordTime GetWheelZoomEndTime() const { return wheelZoomEndTime ; }
  void SetWheelZoomEndTime(TRecordTime value) { wheelZoomEndTime = value ; }

  double GetWheelZoomFactor() const { return wheelZoomFactor ; }
  void SetWheelZoomFactor(double value) { wheelZoomFactor = value ; }

  long GetZoomBegin() const { return zoomBeginX ; }
  void SetZoomBegin(long value) { zoomBeginX = value ; }

  long GetZoomBeginY() const { return zoomBeginY ; }
  void SetZoomBeginY(long value) { zoomBeginY = value ; }

  long GetZoomEnd() const { return zoomEndX ; }
  void SetZoomEnd(long value) { zoomEndX = value ; }

  long GetZoomEndY() const { return zoomEndY ; }
  void SetZoomEndY(long value) { zoomEndY = value ; }

  bool GetZoomXY() const { return zoomXY ; }
  void SetZoomXY(bool value) { zoomXY = value ; }

  bool GetZooming() const { return zooming ; }
  void SetZooming(bool value) { zooming = value ; }

  /// Retrieves bitmap resources
  wxBitmap GetBitmapResource( const wxString& name );

  /// Retrieves icon resources
  wxIcon GetIconResource( const wxString& name );
////@end gTimeline member function declarations

  /// Should we show tooltips?
  static bool ShowToolTips();

  std::vector< TObjectOrder > getCurrentZoomRange();

#ifdef __WXMAC__
  void drawStackedImages( wxDC& dc );
#endif
  void redraw();
  bool drawAxis( wxDC& dc, vector<TObjectOrder>& selected );
  void drawZeroAxis( wxDC& dc, vector<TObjectOrder>& selected );
  
#ifdef _MSC_VER
  template<typename ValuesType>
  void drawRow( wxDC& dc,
                TObjectOrder firstRow,
                vector< ValuesType >& valuesToDraw,
                hash_set< PRV_INT32 >& eventsToDraw,
                hash_set< commCoord >& commsToDraw,
                wxMemoryDC& eventdc, wxMemoryDC& eventmaskdc,
                wxMemoryDC& commdc, wxMemoryDC& commmaskdc );
#else
  template<typename ValuesType>
  void drawRow( wxDC& dc,
                TObjectOrder firstRow,
                vector< ValuesType >& valuesToDraw,
                hash_set< PRV_INT32 >& eventsToDraw,
                hash_set< commCoord, hashCommCoord >& commsToDraw,
                wxMemoryDC& eventdc, wxMemoryDC& eventmaskdc,
                wxMemoryDC& commdc, wxMemoryDC& commmaskdc );
#endif

  template<typename ValuesType>
  void drawRowColor( wxDC& dc, ValuesType valueToDraw, wxCoord objectPos, wxCoord timePos, float magnify );

  template<typename ValuesType>
  void drawRowFunction( wxDC& dc, ValuesType valueToDraw, int& lineLastPos, wxCoord objectPos, wxCoord timePos, float magnify );

  template<typename ValuesType>
  void drawRowPunctual( wxDC& dc, ValuesType& valuesToDrawList, wxCoord objectPos, wxCoord timePos, float magnify );

  template<typename ValuesType>
  void drawRowFusedLines( wxDC& dc, ValuesType valueToDraw, int& lineLastPos, TObjectOrder whichObject, wxCoord timePos, float magnify );

  void drawRowEvents( wxDC& eventdc, wxDC& eventmaskdc, TObjectOrder rowPos, hash_set< PRV_INT32 >& eventsToDraw );
#ifdef _MSC_VER
  void drawRowComms( wxDC& commdc, wxDC& commmaskdc, TObjectOrder rowPos, hash_set< commCoord >& commsToDraw );
#else
  void drawRowComms( wxDC& commdc, wxDC& commmaskdc, TObjectOrder rowPos, hash_set< commCoord, hashCommCoord >& commsToDraw );
#endif
  
  void drawCommunicationLines( bool draw );
  void drawEventFlags( bool draw );
  void drawFunctionLineColor();
  void drawFusedLinesColor();

  void OnPopUpRightDown( void );

  // Pop Up Menu Methods
  void OnPopUpCopy();
  void OnPopUpPasteDefaultSpecial();
  void OnPopUpPasteSpecial();
  void OnPopUpPasteTime();
  void OnPopUpPasteObjects();
  void OnPopUpPasteSize();
  void OnPopUpPasteDuration();
  void OnPopUpPasteSemanticScale();
  void OnPopUpPasteFilterAll();
  void OnPopUpPasteFilterCommunications();
  void OnPopUpPasteFilterEvents();
  void OnPopUpClone();
  void OnPopUpRename();
  void OnPopUpFitTimeScale();
  void OnPopUpFitSemanticScaleMin();
  void OnPopUpFitSemanticScaleMax();
  void OnPopUpFitSemanticScale();
  void OnPopUpFitObjects();
  void OnPopUpPunctualColor();
  void OnPopUpPunctualColorWindow();
  void OnPopUpCodeColor();
  void OnPopUpGradientColor();
  void OnPopUpNotNullGradientColor();
  void OnPopUpUndoZoom();
  void OnPopUpRedoZoom();
  
  void OnPopUpDrawModeTimeLast();
  void OnPopUpDrawModeTimeRandom();
  void OnPopUpDrawModeTimeRandomNotZero();
  void OnPopUpDrawModeTimeMaximum();
  void OnPopUpDrawModeTimeMinimumNotZero();
  void OnPopUpDrawModeTimeAbsoluteMaximum();
  void OnPopUpDrawModeTimeAbsoluteMinimumNotZero();
  void OnPopUpDrawModeTimeAverage();
  void OnPopUpDrawModeTimeAverageNotZero();
  void OnPopUpDrawModeTimeMode();

  void OnPopUpDrawModeObjectsLast();
  void OnPopUpDrawModeObjectsRandom();
  void OnPopUpDrawModeObjectsRandomNotZero();
  void OnPopUpDrawModeObjectsMaximum();
  void OnPopUpDrawModeObjectsMinimumNotZero();
  void OnPopUpDrawModeObjectsAbsoluteMaximum();
  void OnPopUpDrawModeObjectsAbsoluteMinimumNotZero();
  void OnPopUpDrawModeObjectsAverage();
  void OnPopUpDrawModeObjectsAverageNotZero();
  void OnPopUpDrawModeObjectsMode();

  void OnPopUpDrawModeBothLast();
  void OnPopUpDrawModeBothRandom();
  void OnPopUpDrawModeBothRandomNotZero();
  void OnPopUpDrawModeBothMaximum();
  void OnPopUpDrawModeBothMinimumNotZero();
  void OnPopUpDrawModeBothAbsoluteMaximum();
  void OnPopUpDrawModeBothAbsoluteMinimumNotZero();
  void OnPopUpDrawModeBothAverage();
  void OnPopUpDrawModeBothAverageNotZero();
  void OnPopUpDrawModeBothMode();

  void OnPopUpPixelSize( PRV_UINT16 whichPixelSize );

  void OnPopUpRowSelection();

  void OnPopUpInfoPanel();
  
  void OnMenuGradientFunction( GradientColor::TGradientFunction function );
  
  void drawTimeMarks( std::vector< TRecordTime> times,
                      std::vector<TObjectOrder> &selectedObjects,
                      bool drawXCross = false,
                      bool allObjects = true,
                      TObjectOrder lastFoundObject = TObjectOrder(0) );
  void OnFindDialog();

  gTimeline *clone( Window *clonedWindow,
                    wxWindow *parent,
                    wxTreeItemId idRoot1,
                    wxTreeItemId idRoot2,
                    bool mustRedraw = true );

  void rightDownManager();

  void resizeDrawZone( int width, int height );
  
  bool IsSplit() const;
  void OnPopUpTiming( bool whichTiming );
  void OnItemColorLeftUp( wxMouseEvent& event );
  void OnTextColorLeftUp( wxMouseEvent& event );

#ifdef DEFAULT_IMAGE_DIALOG
  void saveImage( bool showSaveDialog, wxString whichFileName  );
  void saveImageLegend( bool showSaveDialog = true  );
  void saveImageDialog( wxString whichFileName );
#else  
  void saveImage( bool showSaveDialog, wxString whichFileName, ParaverConfig::TImageFormat filterIndex = ParaverConfig::PNG );
  void saveImageLegend( bool showSaveDialog = true, wxString whichFileName = _( "" ), ParaverConfig::TImageFormat filterIndex = ParaverConfig::PNG );
  void saveImageDialog( wxString whichFileName );
#endif

  void saveText();
  void saveCFG();

  void setEnableDestroyButton( bool value );

  typedef enum {  RAW_LINE = 0,
                  BEGIN_OBJECT_SECTION,
                  END_OBJECT_SECTION,
                  BEGIN_PREVNEXT_SECTION,
                  END_PREVNEXT_SECTION,
                  BEGIN_CURRENT_SECTION,
                  END_CURRENT_SECTION,
                  BEGIN_SEMANTIC_SECTION,
                  SEMANTIC_LINE,
                  END_SEMANTIC_SECTION,
                  BEGIN_RECORDS_SECTION,
                  MARK_LINE,
                  EVENT_LINE,
                  COMMUNICATION_LINE,
                  END_RECORDS_SECTION } TWWLine;

  static wxProgressDialog *dialogProgress;
  
  
//  void OnRightClick(wxMouseEvent& event);
////@begin gTimeline member variables
  wxSplitterWindow* splitter;
  wxScrolledWindow* drawZone;
  wxNotebook* infoZone;
  wxScrolledWindow* whatWherePanel;
  wxCheckBox* checkWWSemantic;
  wxCheckBox* checkWWEvents;
  wxCheckBox* checkWWCommunications;
  wxCheckBox* checkWWPreviousNext;
  wxCheckBox* checkWWText;
  wxCheckBox* checkWWShowDate;
  wxCheckBox* checkWWHex;
  wxRichTextCtrl* whatWhereText;
  wxScrolledWindow* timingZone;
  wxTextCtrl* initialTimeText;
  wxStaticText* initialSemanticLabel;
  wxTextCtrl* initialSemanticText;
  wxTextCtrl* finalTimeText;
  wxStaticText* finalSemanticLabel;
  wxTextCtrl* finalSemanticText;
  wxTextCtrl* durationText;
  wxStaticText* slopeLabel;
  wxTextCtrl* slopeText;
  wxScrolledWindow* colorsPanelGlobal;
  wxCheckBox* checkboxCustomPalette;
  wxButton* buttonCustomPaletteApply;
  wxScrolledWindow* colorsPanel;
  wxBoxSizer* colorsSizer;
  wxBoxSizer* sizerSelectedColor;
  wxPanel* panelSelectedColor;
  wxStaticText* labelSelectedColorRed;
  wxSlider* sliderSelectedRed;
  wxStaticText* labelSelectedColorGreen;
  wxSlider* sliderSelectedGreen;
  wxStaticText* labelSelectedColorBlue;
  wxSlider* sliderSelectedBlue;
  wxBitmap bufferImage;
  wxBitmap commImage;
  bool drawCaution;
  wxBitmap drawImage;
  wxBitmap eventImage;
  wxColour physicalColour;
private:
  wxColour backgroundColour;
  long beginRow;
  bool canRedraw;
  bool drawCautionNegatives;
  long endRow;
  bool escapePressed;
  TRecordTime findBeginTime;
  TRecordTime findEndTime;
  TObjectOrder findFirstObject;
  TObjectOrder findLastObject;
  wxMouseEvent firstMotionEvent;
  bool firstUnsplit;
  wxColour foregroundColour;
  int infoZoneLastSize;
  TRecordTime lastEventFoundTime;
  TObjectOrder lastFoundObject;
  TRecordTime lastSemanticFoundTime;
  wxColour logicalColour;
  wxPen logicalPen;
  wxMouseEvent motionEvent;
  Window* myWindow;
  PRV_INT32 objectAxisPos;
  wxFont objectFont;
  int objectHeight;
  vector<PRV_INT32> objectPosList;
  wxPen physicalPen;
  bool redoColors;
  wxStopWatch * redrawStopWatch;
  std::map< rgb, std::set<TSemanticValue> > semanticColorsToValue;
  wxFont semanticFont;
  std::map< int, std::set<TSemanticValue> >  semanticPixelsToValue; // // Used by function line drawings
  std::map< TSemanticValue, rgb > semanticValuesToColor; // Stored for SaveImage legend
  bool splitChanged;
  PRV_INT32 timeAxisPos;
  wxFont timeFont;
  wxTimer * timerMotion;
  wxTimer * timerSize;
  wxTimer * timerWheel;
  bool timing;
  TObjectOrder wheelZoomBeginObject;
  TRecordTime wheelZoomBeginTime;
  TObjectOrder wheelZoomEndObject;
  TRecordTime wheelZoomEndTime;
  double wheelZoomFactor;
  long zoomBeginX;
  long zoomBeginY;
  long zoomEndX;
  long zoomEndY;
  bool zoomXY;
  bool zooming;
////@end gTimeline member variables

  // colorsPanel update info
  bool forceRedoColors;
  bool enableApplyButton;
  SemanticInfoType lastType;
  TSemanticValue lastMin;
  TSemanticValue lastMax;
  size_t lastValuesSize;
  bool codeColorSet;
  GradientColor::TGradientFunction gradientFunc;
  TSemanticValue selectedCustomValue;
  wxPanel *selectedItemColor;

#ifdef __WXMAC__
  wxBitmap zoomBMP;
#endif
#ifdef WIN32
  bool wheelZoomObjects;
#endif

  wxWindow *parent;
  
  static const wxCoord drawBorder = 5;

  vector< pair< TWWLine, wxString > > whatWhereLines;
  int whatWhereSelectedTimeEventLines;
  int whatWhereSelectedTimeCommunicationLines;
  TRecordTime    whatWhereTime;
  TObjectOrder   whatWhereRow;
  TSemanticValue whatWhereSemantic;

  wxString formatTime( TRecordTime whichTime, bool showDate );
  void computeWhatWhere( TRecordTime whichTime,
                         TObjectOrder whichRow,
                         TSemanticValue whichSemantic,
                         bool textMode,
                         bool showDate,
                         bool hexMode );
  void printWhatWhere( );
  void printWWSemantic( TObjectOrder whichRow, bool clickedValue, bool textMode, bool hexMode );
  void printWWRecords( TObjectOrder whichRow, bool clickedValue, bool textMode, bool showDate );

  TSemanticValue getSemanticValueFromFusedLines( int whichY );
  bool getPixelFromFunctionLine( int whichX, int whichY, TObjectOrder whichObject, int& whichPixelPos );


  // Returns: window_name_with_spaces_underscored@traceName (without extension PRV)
  wxString buildFormattedFileName() const;

  void Unsplit();
  void Split();
  void OnTimerSize( wxTimerEvent& event );
  void OnTimerMotion( wxTimerEvent& event );
  void OnTimerWheel( wxTimerEvent& event );

  bool pixelToTimeObject( long x, long y, TTime& onTime, TObjectOrder& onObject );
  
  void doDrawCaution( wxDC& whichDC );
  
  // Called by saveLabelsImage
  void drawRectangle( wxMemoryDC& labelDC,
                       wxMemoryDC& scaleDC,
                       wxColour foregroundColour,
                       wxColour backgroundColour,
                       rgb semanticColour,
                       wxString semanticValueLabel,
                       int titleMargin,
                       int widthRect,
                       int heightRect,
                       bool tryHorizontal,
                       int& xdst,
                       int& ydst,
                       int xsrc,
                       int ysrc,
                       int imageWidth,
                       int imageHeight,
                       int imageStepY,
                       int imageStepXRectangle,
                       bool drawLabel );

  void setEnableDestroyParents( bool value );

  class ScaleImageVertical
  {
    public:
      ScaleImageVertical(
              Window* whichMyWindow,
              const std::map< TSemanticValue, rgb >& whichSemanticValues,
              wxColour whichBackground,
              wxColour whichForeground,
              int whichBackgroundMode, // wxSOLID or wxTRANSPARENT; wxTRANSPARENT overrides fore and back
              wxFont whichTextFont,
              wxString& whichImagePath,
              const wxString& whichImageInfix,
#if wxMAJOR_VERSION<3
              long whichImageType );
#else
              wxBitmapType& whichImageType );
#endif

      ~ScaleImageVertical();

      void process();
      void save();
      wxImage *getImage() { return scaleImage; }
      wxBitmap *getBitmap() { return scaleBitmap; }

    protected:
      virtual void init();
      virtual void sortSemanticValues();
      virtual void computeMaxLabelSize();
      virtual void computeImageSize();
      virtual void createDC();
      virtual void draw();
      virtual void bitmapToImage();
      virtual wxString buildScaleImagePath();
      virtual void drawLabeledRectangle( rgb semanticColour,
                                         wxString semanticValueLabel,
                                         bool drawIt = true );
      void destroyDC();

      Window *myWindow;
      std::map< TSemanticValue, rgb > semValues;
      wxColour background;
      wxColour foreground;
      int backgroundMode;
      wxFont textFont;
      wxString& imagePath;
      wxString imageInfix;
#if wxMAJOR_VERSION<3
      long imageType;
#else
      wxBitmapType& imageType;
#endif
      ParaverConfig::TImageFormat filterIndex;
      wxString tmpSuffix;
      TSemanticValue currentMin;
      TSemanticValue currentMax;
      std::vector< TSemanticValue > keys;
      PRV_UINT32 precision;
      wxString extraPrefixOutlier;
      std::map< TSemanticValue, wxString > semanticValueLabel;
      TSemanticValue semanticValueWithLongestLabel;
      int titleMargin;
      int widthRect;
      int heightRect;
      int imageStepY;
      int imageStepXRectangle;
      bool drawOutliers;
      bool symbolicDesc;
      int imageWidth;
      int imageHeight;
      int xsrc;
      int ysrc;
      int xdst;
      int ydst;
      wxBitmap *scaleBitmap;
      wxMemoryDC *scaleDC;
      wxBitmap *scaleMaskBitmap;
      wxMemoryDC *scaleMaskDC;
      wxSize maxLabelSize;
      wxImage *scaleImage;
  };

  class ScaleImageVerticalCodeColor : public ScaleImageVertical
  {
    public:
      ScaleImageVerticalCodeColor(
              Window* whichMyWindow,
              const std::map< TSemanticValue, rgb >& whichSemanticValues,
              wxColour whichBackground,
              wxColour whichForeground,
              int whichBackgroundMode,
              wxFont whichTextFont,
              wxString& whichImagePath,
              const wxString& whichImageInfix,
#if wxMAJOR_VERSION<3
              long whichImageType );
#else
              wxBitmapType& whichImageType );
#endif

      ~ScaleImageVerticalCodeColor()
      {}

    protected:
      virtual void init();
  };

  class ScaleImageVerticalGradientColor : public ScaleImageVertical
  {
    public:
      ScaleImageVerticalGradientColor(
              Window* whichMyWindow,
              const std::map< TSemanticValue, rgb >& whichSemanticValues,
              wxColour whichBackground,
              wxColour whichForeground,
              int whichBackgroundMode,
              wxFont whichTextFont,
              wxString& whichImagePath,
              const wxString& whichImageInfix,
#if wxMAJOR_VERSION<3
              long whichImageType );
#else
              wxBitmapType& whichImageType );
#endif

      ~ScaleImageVerticalGradientColor()
      {}

    protected:
      int numSquaresWithoutOutliers;
      int totalSquares;

      virtual void init();
      virtual void sortSemanticValues();
      virtual void draw();
  };

  class ScaleImageVerticalFusedLines : public ScaleImageVertical
  {
    public:
      ScaleImageVerticalFusedLines(
              Window* whichMyWindow,
              const std::map< TSemanticValue, rgb >& whichSemanticValues,
              wxColour whichBackground,
              wxColour whichForeground,
              int whichBackgroundMode,
              wxFont whichTextFont,
              wxString& whichImagePath,
              const wxString& whichImageInfix,
#if wxMAJOR_VERSION<3
              long whichImageType );
#else
              wxBitmapType& whichImageType );
#endif

      ~ScaleImageVerticalFusedLines()
      {}

    protected:
      virtual void init();
      virtual void computeMaxLabelSize();
  };


  class ScaleImageHorizontalGradientColor : public ScaleImageVerticalGradientColor
  {
    public:
      ScaleImageHorizontalGradientColor(
              Window* whichMyWindow,
              const std::map< TSemanticValue, rgb >& whichSemanticValues,
              wxColour whichBackground,
              wxColour whichForeground,
              int whichBackgroundMode,
              wxFont whichTextFont,
              wxString& whichImagePath,
              const wxString& whichImageInfix,
#if wxMAJOR_VERSION<3
              long whichImageType,
#else
              wxBitmapType& whichImageType,
#endif
              int whichWantedWidth = 0 );


      ~ScaleImageHorizontalGradientColor()
      {}

    protected:
      virtual void init();
      virtual void computeImageSize();
      virtual void draw();

    private:
      typedef enum { LEFT = 0, CENTER, RIGHT } TAlign;
      typedef enum { FIRST = 0, MIDDLE, LAST, ANY } TPosition;

      int SIZE_OF_TINY_MARK;
      int outlierMargin; // Inner margin between outlier and whole scale
      int wantedWidth;

      void drawRectangle( rgb semanticColour, TPosition position = ANY );
      void drawLabel( wxString semanticValueLabel, bool drawIt = true, TAlign align = LEFT );
  };
};

void progressFunctionTimeline( ProgressController *progress, void *callerWindow );

#endif  // _GTIMELINE_H_
