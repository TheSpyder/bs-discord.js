module Channel = {
  type t;
  [@bs.get] external channelType: t => string = "type";
};

module User = {
  type t;
  [@bs.get] external bot: t => bool = "bot";
};

module Message = {
  type t;
  [@bs.get] external content: t => string = "";
  [@bs.get] external channel: t => Channel.t = "";
  [@bs.send] external reply: (t, string) => unit = "";
  [@bs.get] external author: t => User.t = "";
};

module ClientUser = {
  type t;
  [@bs.send] external setActivity: t => string => unit = "";
}

module Client = {
  type t;
  [@bs.module "discord.js"] [@bs.new] external createClient: unit => t = "Client";
  [@bs.send] external login: (t, string) => unit = "";
  [@bs.send] external onReady: (t, [@bs.as "ready"] _, unit => unit) => unit = "on";
  [@bs.send] external onMessage: (t, [@bs.as "message"] _, Message.t => unit) => unit = "on";
  [@bs.get] external user: t => ClientUser.t = "";
};