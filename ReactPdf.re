module ReactPDFRe = {
  [@bs.module "@react-pdf/renderer"] [@bs.scope "default"]
  external render: (ReasonReact.reactElement, string) => Js.Promise.t(unit) =
    "render";
};

module StyleSheet = {
  type t('a) = Js.t('a);
  
  [@bs.module "@react-pdf/renderer"] [@bs.scope "StyleSheet"]
  external create: Js.t('a) => t('a) = "";
};

module Document = {
  [@bs.module "@react-pdf/renderer"]
  external document: ReasonReact.reactClass = "Document";
  let make =
      (
        ~title: option(string)=?,
        ~author: option(string)=?,
        ~subject: option(string)=?,
        ~keywords: option(string)=?,
        ~creator: option(string)=?,
        ~producer: option(string)=?,
        ~onRender: option(unit => unit)=?,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=document,
      ~props=
        Js.Nullable.{
          "title": fromOption(title),
          "author": fromOption(author),
          "subject": fromOption(subject),
          "keywords": fromOption(keywords),
          "creator": fromOption(creator),
          "producer": fromOption(producer),
          "onRender": fromOption(onRender),
        },
    );
};

module Page = {
  [@bs.module "@react-pdf/renderer"]
  external reactClass: ReasonReact.reactClass = "Page";

  /* define pageSize and orientation types later */
  let make =
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
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.{
          "size": fromOption(size),
          "orientation": fromOption(orientation),
          "wrap": fromOption(wrap),
          "style": fromOption(style),
          "debug": fromOption(debug),
          "ruler": fromOption(ruler),
          "rulerSteps": fromOption(rulerSteps),
          "verticalRuler": fromOption(verticalRuler),
          "verticalRulerSteps": fromOption(verticalRulerSteps),
          "horizontalRuler": fromOption(horizontalRuler),
          "horizontalRulerSteps": fromOption(horizontalRulerSteps),
        },
    );
};

module View = {
  [@bs.module "@react-pdf/renderer"]
  external reactClass: ReasonReact.reactClass = "View";

  type renderPropsType = {pageNumber: int};

  let make =
      (
        ~wrap: option(bool)=?,
        ~style: option(StyleSheet.t('a))=?,
        ~debug: option(bool)=?,
        ~render: option(renderPropsType => ReasonReact.reactElement)=?,
        ~fixed: option(bool)=?,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.{
          "wrap": fromOption(wrap),
          "style": fromOption(style),
          "debug": fromOption(debug),
          "render": fromOption(render),
          "fixed": fromOption(fixed),
        },
    );
};

module Text = {
  [@bs.module "@react-pdf/renderer"]
  external reactClass: ReasonReact.reactClass = "Text";

  type renderPropsType = {pageNumber: int, totalPages: int};

  let make =
      (
        ~wrap: option(bool)=?,
        ~style: option(StyleSheet.t('a))=?,
        ~debug: option(bool)=?,
        ~render: option(renderPropsType => ReasonReact.reactElement)=?,
        ~fixed: option(bool)=?,
        ~hyphenationCallback: option(int)=?,
        children
      ) =>
    {
      ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.{
          "wrap": fromOption(wrap),
          "style": fromOption(style),
          "debug": fromOption(debug),
          "render": fromOption(render),
          "fixed": fromOption(fixed),
          "hyphenationCallback": fromOption(hyphenationCallback),
        },
        children
    );
    }
};

module Image = {
  [@bs.module "@react-pdf/renderer"]
  external reactClass: ReasonReact.reactClass = "Image";

  let make =
      (
        ~src: option(string)=?,
        ~style: option(StyleSheet.t('a))=?,
        ~debug: option(bool)=?,
        ~fixed: option(bool)=?,
        ~cache: option(bool)=?,
        ~safePath: option(string)=?,
        ~allowDangerousPaths : option(bool)=?,
        children
      ) =>
    {
      ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.{
          "src": fromOption(src),
          "style": fromOption(style),
          "debug": fromOption(debug),
          "fixed": fromOption(fixed),
          "cache": fromOption(cache),
          "safePath": fromOption(safePath),
          "allowDangerousPaths": fromOption(allowDangerousPaths),
        },
        children
    );
    }
};

module PDFViewer = {
  [@bs.module "@react-pdf/renderer"]
  external reactClass: ReasonReact.reactClass = "PDFViewer";

  type renderPropsType = {pageNumber: int};

  let make =
      (
        ~style: option(StyleSheet.t('a))=?,
        ~className: option(string)=?,
        ~children: option(ReasonReact.reactElement)=?,
        ~width: option(string)=?,
        ~height: option(string)=?,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.{
          "style": fromOption(style),
          "className": fromOption(className),
          "children": fromOption(children),
          "width": fromOption(width),
          "height": fromOption(height),
        },
    );
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
  external register: Js.t('a) => unit = "";
};
