module ReactPDFRe = {
  [@bs.module "@react-pdf/renderer"] [@bs.scope "default"]
  external render: (React.element, string) => Js.Promise.t(unit) =
    "render";
};

module StyleSheet = {
  type t('a) = Js.t('a);
  
  [@bs.module "@react-pdf/renderer"] [@bs.scope "StyleSheet"]
  external create: Js.t('a) => t('a) = "create";
};

module Document = {
  [@bs.module "@react-pdf/renderer"][@react.component]
  external make: (
    ~title: option(string)=?,
    ~author: option(string)=?,
    ~subject: option(string)=?,
    ~keywords: option(string)=?,
    ~creator: option(string)=?,
    ~producer: option(string)=?,
    ~onRender: option(unit => unit)=?
    ~children: React.element,
    ) => React.element = "Document";
};

module Page = {
  [@bs.module "@react-pdf/renderer"][@react.component]
  external make:
      (
        ~size: option(string)=?,
        ~orientation: option(string)=?,
        ~wrap: option(bool)=?,
        ~style: option(StyleSheet.t('a))=?,
        ~debug: option(bool)=?,
        ~ruler: option(bool)=?,
        ~rulerSteps: option(int)=?,
        ~verticalRuler: option(bool)=?,
        ~verticalRulerSteps: option(int)=?,
        ~horizontalRuler: option(bool)=?,
        ~horizontalRulerSteps: option(int)=?,
        ~children: React.element,
      ) => React.element = "Page"
};

module View = {
  type renderPropsType = {pageNumber: int};

  [@bs.module "@react-pdf/renderer"][@react.component]
  external make: (
    ~wrap: option(bool)=?,
    ~style: option(StyleSheet.t('a))=?,
    ~debug: option(bool)=?,
    ~render: option(renderPropsType => ReasonReact.reactElement)=?,
    ~fixed: option(bool)=?,
    ~children: React.element,
  ) => React.element = "View";
};

module Text = {
  type renderPropsType = {pageNumber: int, totalPages: int};

  [@bs.module "@react-pdf/renderer"][@react.component]
  external make: (
    ~wrap: option(bool)=?,
    ~style: option(StyleSheet.t('a))=?,
    ~debug: option(bool)=?,
    ~render: option(renderPropsType => React.element)=?,
    ~fixed: option(bool)=?,
    ~hyphenationCallback: option(int)=?,
    ~children: React.element
  ) => React.element = "Text";
};

module Image = {
  [@bs.module "@react-pdf/renderer"][@react.component]
  external make: (
        ~src: option(string)=?,
        ~style: option(StyleSheet.t('a))=?,
        ~debug: option(bool)=?,
        ~fixed: option(bool)=?,
        ~cache: option(bool)=?,
        ~safePath: option(string)=?,
        ~allowDangerousPaths : option(bool)=?
  ) => React.element = "Image";
};

module PDFViewer = {

  [@bs.module "@react-pdf/renderer"][@react.component]
  external make: (
    ~style: option(StyleSheet.t('a))=?,
    ~className: option(string)=?,
    ~width: option(string)=?,
    ~height: option(string)=?,
    ~children: React.element=?,
  ) => React.element = "PDFViewer";
};

module Font = {
  type fontParams;

  [@bs.obj] external makeFontParams:
    (
      ~src: string,
      ~fontStyle: string=?,
      ~fontWeight: int=?,
      unit
    ) =>
    fontParams =
    "";

  [@bs.obj]
  external makeRegisterInput:
    (
      ~family: string,
      ~src: string,
      ~fonts: array(fontParams)=?,
      unit
    ) =>
    _ =
    "";

  [@bs.module "@react-pdf/renderer"] [@bs.scope "Font"]
  external register: Js.t('a) => unit = "register";
};
