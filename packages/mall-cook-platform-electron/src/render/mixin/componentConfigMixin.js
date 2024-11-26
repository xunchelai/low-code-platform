/*
 * @Description: What's this for
 *  
 *   @Date: 2024-09-26 20:49:31
 *   
 * @LastEditTime: 2024-01-18 16:16:32
 */
/*
 * @Description: 组件配置混入
 *  
 *   @Date: 2024-06-04 16:31:11
 *   
 * @LastEditTime: 2024-09-18 10:51:49
 */

import ModeSelect from "@/components/ModeSelect";
import ModeSelectItem from "@/components/ModeSelect/ModeSelectItem";

export default {
    components: {
        ModeSelect,
        ModeSelectItem,
    },
    props: {
        attr: {
            type: Object,
            default: () => { }
        },
        style: {
            type: Object,
            default: () => { }
        },
        value: {
            type: Object,
            default: () => { }
        },
    },
}