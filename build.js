'use strict';

const { join } = require('path');

module.exports = async (tools, consts, MODE) => {
  const { replaceDir, execSync, colorize, $ } = tools;
  const { VCVARSALL, CL, _LIB } = consts;

  const config = {
    envArg: [ 'amd64' ],

    compilerArg: [
      join(__dirname, 'src/xgk-cpp-engine.cpp'),

      '/EHsc',
      '/MT',
      '/MP999',
      '/c',
      '/std:c++17',

      `/D${ MODE }`,

      '/IE:/reps/xgk/xgk-cpp-engine/src',
    ],

    libArg: [
      'xgk-cpp-engine.obj',

      `/OUT:${ join(__dirname, MODE, 'xgk-cpp-engine.lib') }`,
    ],
  };

  const { envArg, compilerArg, libArg } = config;

  replaceDir(join(__dirname, MODE));

  colorize(await execSync(`${ $(VCVARSALL, envArg) } && ${ $(CL, compilerArg) } && ${ $(_LIB, libArg) }`));
};
