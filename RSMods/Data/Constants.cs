﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RSMods.Data
{
    public static class Constants
    {
        private static string _rsFolder;

        public static string RSFolder 
        {
            get { return _rsFolder; }  // return @"C:\Program Files (x86)\Steam\steamapps\common\Rocksmith2014";
            set { _rsFolder = value; }
        } 
        public static string CachePsarcPath { get { return Path.Combine(RSFolder, "cache.psarc"); } }
        public static string WorkFolder { get { return Path.Combine(Path.GetDirectoryName(Application.ExecutablePath), "Temp"); } }
        public static string CachePcPath { get { return Path.Combine(WorkFolder, "cache.psarc_RS2014_Pc"); } }
        public static string Cache4_7zPath { get { return Path.Combine(CachePcPath, "cache4.7z"); } }
        public static string Cache7_7zPath { get { return Path.Combine(CachePcPath, "cache7.7z"); } }
        public static string LocalizationCSV_InternalPath { get { return Path.Combine("localization", "maingame.csv"); } }
        public static string TuningsJSON_InternalPath { get { return Path.Combine("manifests", "tuning.database.json"); } }
        public static string CustomModsFolder { get { return Path.Combine(Path.GetDirectoryName(Application.ExecutablePath), "CustomMods"); } }
        public static string LocalizationCSV_CustomPath { get { return Path.Combine(CustomModsFolder, "maingame.csv"); } }
        public static string TuningJSON_CustomPath { get { return Path.Combine(CustomModsFolder, "tuning.database.json"); } }
        public static string IntroGFX_InternalPath { get { return Path.Combine("gfxassets", "views", "introsequence.gfx"); } }
        public static string IntroGFX_CustomPath { get { return Path.Combine(CustomModsFolder, "introsequence.gfx"); } }
        public static string CacheBackupPath { get { return Path.Combine(RSFolder, "cache.bak"); } }
    }
}
