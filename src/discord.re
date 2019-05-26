
module RichEmbed = {
  type t;
  [@bs.module "discord.js"] [@bs.new] external create: unit => t = "RichEmbed";
  [@bs.send] external title: t => string => t = "setTitle";
  [@bs.send] external color: t => string => t = "setColor";
  [@bs.send] external description: t => string => t = "setDescription";
};

module Channel = {
  type t;
  [@bs.get] external channelType: t => string = "type";
  [@bs.get] external name: t => string = "name";
  [@bs.send] external sendEmbed: t => RichEmbed.t => unit = "send";
  [@bs.send] external send: t => string => unit = "send";
};

module User = {
  type t;
  [@bs.get] external bot: t => bool = "bot";
  [@bs.get] external name: t => string = "username";
};

module Message = {
  type t;
  [@bs.get] external content: t => string = "";
  [@bs.get] external channel: t => Channel.t = "";
  [@bs.send] external reply: (t, string) => unit = "";
  [@bs.get] external author: t => User.t = "";
  [@bs.send] external delete: t => unit = "";
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