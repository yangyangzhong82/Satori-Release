### **📌 Satori 事件日志插件**  

#### **📝 插件简介**  
Satori 是一款专为 **Minecraft 基岩版服务器** 打造的 **高性能事件日志记录插件**，能够监听服务器中的各类事件，并将其详细记录到 **日志文件或控制台**，帮助管理员 **高效监控** 和 **分析服务器动态**。  

#### **✨ 主要功能**  
- **📊 服务器管理**  
  - 追踪 **玩家行为**，检测 **异常活动**，便于 **安全审计** 和 **事后追查**，极大提升服务器管理效率。  
- **📌 丰富事件记录**  
  - **支持 60+ 种事件**，全面监控服务器，例如 **方块破坏、放置、爆炸、聊天、实体生成、玩家交互** 等关键操作。  
- **⚡ 高性能优化**  
  - **C++ 编写**，原生插件，确保极致性能。  
  - 采用 **缓存技术** 和 **异步写入**，避免影响服务器主线程，提高运行效率。  
- **⚙️ 灵活可配置**  
  - **自定义监控项**，可自由 **启用/禁用事件、调整日志输出方式、忽略特定内容**，满足不同服务器需求。  
- **🔗 强大扩展性**  
  - 提供 **丰富的 API**，支持 **第三方插件调用**，适用于 **高级数据分析** 等扩展功能。  

**Satori 让你的服务器管理更加高效、直观、安全，是每位服务器管理员的必备工具！ 🚀**  

---

## **🔧 使用指南**  

### **📥 安装插件**  
1. **前置依赖**  
   - 本插件 **依赖 [iListenAttentively](https://github.com/MiracleForest/iListenAttentively-Release/releases)**，请先下载安装该插件。  
2. **下载插件**  
   - 前往 **[Satori Releases](https://github.com/TelluriumDev/Satori/releases)** 页面，下载最新版本。  
3. **安装插件**  
   - 将插件解压到 `plugins` 目录，确保 **Satori 能够正确加载**。  
4. **启动服务器**  
   - 若控制台出现 `[LeviLamina] 正在加载 Satori vX.X.X` 且无报错，则说明安装成功！  

### **📂 日志存储**  
- **数据库文件**：日志储存在 `data/Satori.db`  
- **查看方式**：可使用 **SQLiteStudio** 或其他数据库管理工具进行查询。  

---

## **📁 配置文件 (config.json) 说明**  
Satori 允许你 **自由调整监控项**，配置文件位于config/config.json中，以下是配置选项说明：  

```jsonc
{
    "version": 1,  // 版本号，不要动
    "enabled": true,  // 是否启用插件
    "maxThreads" : 4, //最大使用的线程数量
    "databaseFilePath": "Satori.db",  // 数据库储存目录
    "regexFilters": [
    {
      "pattern": "\\\"Message\\\":\\s*\\\".*广告.*\\\"",
      "description": "过滤聊天中的广告信息",
      "applyToEvents": ["PlayerChat"]
    },
    {
      "pattern": "\\\"uuid\\\":\\s*\\\"00000000-0000-0000-0000-000000000001\\\"",
      "description": "过滤特定玩家的加入事件",
      "applyToEvents": ["PlayerJoin"]
    },
    {
      "pattern": "minecraft:tnt",
      "description": "过滤所有涉及 TNT 的事件",
      "applyToEvents": [] // 空数组表示应用于所有事件
    },
    {
      "pattern": "\\\"Block\\\":\\s*\\\"minecraft:bedrock\\\"",
      "description": "过滤玩家破坏基岩的事件",
      "applyToEvents": ["PlayerDestroyBlock"]
    }
  ],
    "settings": {
        "ServerStarted": {  // 服务器启动事件
            "enabled": true,  // 是否启用
            "logToFile": true,  // 是否记录到文件
            "logToConsole": false  // 是否输出到控制台
        },
        "ChestPairWith": {  // 箱子合成事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "WeatherUpdate": {  // 天气更新事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "FireSpread": {  // 火焰蔓延事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "ServerStopping": {  // 服务器停止事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "ExecutedCommand": {  // 玩家执行指令事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "SpawnMob": {  // 实体生成事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "PlayerConnect": {  // 玩家连接服务器事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "PlayerChat": {  // 玩家聊天事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "DragonRespawn": {  // 末影龙重生事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "BlockChanged": {  // 方块变化事件
            "enabled": false,  
            "logToFile": true,
            "logToConsole": false
        },
        "PlayerAte": {  // 玩家进食事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "PlayerSneaking": {  // 玩家潜行事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "Explosion": {  // 爆炸事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "PistonPush": {  // 活塞推动方块事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "FireTryBurnBlock": {  // 火焰尝试点燃方块事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "RedstoneUpdate": {  // 红石更新事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "SculkBlockGrowth": {  // 诡异块生长事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "PlayerSprinting": {  // 玩家疾跑事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "SpawnItemActor": {  // 物品生成事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "ActorGetEffect": {  // 实体获得状态效果事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "SpawnWanderingTrader": {  // 流浪商人生成事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "PlayerPlaceBlock": {  // 玩家放置方块事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "PlayerJump": {  // 玩家跳跃事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "DeathMessage": {  // 死亡信息事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "WitherDestroy": {  // 凋零破坏方块事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "DragonEggBlockTeleport": {  // 龙蛋传送事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "MobHurtEffect": {  // 生物受伤效果事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "FarmDecay": {  // 农作物枯萎事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "PlayerOperatedItemFrame": {  // 玩家操作物品展示框事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "MossGrowth": {  // 苔藓生长事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "SculkCatalystAbsorbExperience": {  // 幽匿催发体方块转换事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "PlayerOpenContainer": {  // 玩家打开容器事件（如箱子）
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "ActorHurt": {  // 实体受伤事件
            "enabled": false,
            "logToFile": true,
            "logToConsole": false
        },
        "MobDie": {  // 生物死亡事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "ActorChangeDimension": {  // 实体跨维度事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "PlayerJoin": {  // 玩家加入服务器事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "PlayerRespawn": {  // 玩家重生事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "PlayerEditSign": {  // 玩家编辑告示牌事件
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "LiquidFlow": {// 液体流动
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "PlayerStopSleep": {// 玩家停止睡觉
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "MobHealthChange": {// 生物血量变化
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        },
        "FireworkRocketDealDamage": {// 烟花火箭受伤
            "enabled": true,
            "logToFile": true,
            "logToConsole": false
        }
    }
}
```



