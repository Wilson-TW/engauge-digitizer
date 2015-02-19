#ifndef CURVE_STYLES_H
#define CURVE_STYLES_H

#include "ColorPalette.h"
#include "LineStyle.h"
#include "LineStyles.h"
#include "PointStyle.h"
#include "PointStyles.h"

class Document;
class QXmlStreamWriter;

/// Model for DlgSettingsCurveProperties and CmdSettingsCurveProperties.
class CurveStyles
{
public:
  /// Default constructor.
  CurveStyles();

  /// Initial constructor from Document.
  CurveStyles(const Document &document);

  /// Copy constructor.
  CurveStyles (const CurveStyles &other);

  /// Assignment constructor.
  CurveStyles &operator=(const CurveStyles &other);
  
  /// Get method for line color in specified curve.
  ColorPalette lineColor (const QString &curveName) const;

  /// Get method for connect as method for lines in specified curve.
  CurveConnectAs lineConnectAs (const QString &curveName) const;

  /// Get method for copying one line style in one step.
  const LineStyle lineStyle (const QString &curveName) const;

  /// Get method for copying all line styles in one step.
  const LineStyles &lineStyles () const;

  /// Get method for line width in specified curve.
  double lineWidth (const QString &curveName) const;

  /// Get method for curve point color in specified curve.
  ColorPalette pointColor (const QString &curveName) const;

  /// Get method for curve point is circle in specified curve.
  bool pointIsCircle (const QString &curveName) const;

  /// Get method for curve point line width.
  double pointLineWidth (const QString &curveName) const;

  /// Get method for curve point polygon in specified curve.
  QPolygonF pointPolygon (const QString &curveName) const;

  /// Get method for curve point radius.
  int pointRadius (const QString &curveName) const;

  /// Get method for curve point shape.
  PointShape pointShape(const QString &curveName) const;

  /// Get method for copying one point style. Cannot return just a reference or else there is a warning about returning reference to temporary
  const PointStyle pointStyle (const QString &curveName) const;

  /// Get method for copying all point styles in one step.
  const PointStyles &pointStyles () const;

  /// Serialize to xml
  void saveDocument(QXmlStreamWriter &writer) const;

  /// Set method for line color in specified curve.
  void setLineColor (const QString &curveName,
                     ColorPalette lineColor);

  /// Set method for connect as method for lines in specified curve.
  void setLineConnectAs (const QString &curveName,
                         CurveConnectAs curveConnectAs);

  /// Set method for line width in specified curve.
  void setLineWidth (const QString &curveName,
                     int width);

  /// Set method curve point color in specified curve.
  void setPointColor (const QString &curveName,
                      ColorPalette curveColor);

  /// Set method for curve point is circle in specified curve.
  void setPointIsCircle (const QString &curveName,
                         bool pointIsCircle);

  /// Set method for curve point perimeter line width.
  void setPointLineWidth (const QString &curveName,
                          double width);

  /// Set method for curve point radius.
  void setPointRadius (const QString &curveName,
                       int radius);

  /// Set method for curve point shape in specified curve.
  void setPointShape (const QString &curveName,
                      PointShape shape);

private:

  LineStyles m_lineStyles;
  PointStyles m_pointStyles;
};

#endif // CURVE_STYLES_H