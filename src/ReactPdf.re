type arrayBuffer;

type pdfBlob;

type pdfData = {
  toBlob: unit => Js.Promise.t(pdfBlob)
};

type blobProviderparams = {
    loading: bool
};

[@bs.send] external blobArrayBuffer: (pdfBlob, unit) => Js.Promise.t(arrayBuffer) = "arrayBuffer";

let getBlobArrayBuffer = (blob: pdfBlob) : Js.Promise.t(arrayBuffer) => blobArrayBuffer(blob, ());

module ReactPDFRe = {
  [@bs.module "@react-pdf/renderer"] [@bs.scope "default"]
  external render: (React.element, string) => Js.Promise.t(unit) =
    "render";

  [@bs.module "@react-pdf/renderer"]
  external getPdfData: React.element => pdfData = "pdf";


  let getBlob = (document: React.element) : Js.Promise.t(pdfBlob) => getPdfData(document).toBlob();

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
    ~onRender: option(unit => unit)=?,
    ~children: React.element
    ) => React.element = "Document";
};

module Page = {
  module Size: {
    type t;
    let string: string => t;
    let int: int => t;
  } = {
    [@unboxed]
    type t =
      | Size('a): t;
    let string = (v: string) => Size(v);
    let int = (v: int) => Size(v);
  };

  [@bs.module "@react-pdf/renderer"][@react.component]
  external make:
      (
        ~size: option(Size.t)=?,
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
        ~src: string,
        ~style: option(StyleSheet.t('a))=?,
        ~debug: option(bool)=?,
        ~fixed: option(bool)=?,
        ~cache: option(bool)=?,
        ~safePath: option(string)=?,
        ~allowDangerousPaths : option(bool)=?
  ) => React.element = "Image";
};

module Link = {
  [@bs.module "@react-pdf/renderer"][@react.component]
  external make: (
    ~src: string,
    ~wrap: option(bool)=?,
    ~debug: option(bool)=?,
    ~style: option(StyleSheet.t('a))=?,
    ~children: option(React.element)=?,
  ) => React.element = "Link";
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

module PDFDownloadLink = {
  [@bs.module "@react-pdf/renderer"][@react.component]
  external make: (
      ~document: React.element,
      ~fileName: option(string)=?,
      ~style: option(StyleSheet.t('a))=?,
      ~className: option(string)=?,
      ~children: blobProviderparams => React.element
  ) => React.element = "PDFDownloadLink";
};

module BlobProvider = {
  [@bs.module "@react-pdf/renderer"][@react.component]
  external make: (
    ~document: React.element,
    ~children: blobProviderparams => React.element
  ) => React.element = "BlobProvider";
};
