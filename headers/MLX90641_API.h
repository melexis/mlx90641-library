/**
 * @copyright (C) 2017 Melexis N.V.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef _MLX641_API_H_
#define _MLX641_API_H_
    
  typedef struct
    {
        int16_t kVdd;
        int16_t vdd25;
        float KvPTAT;
        float KtPTAT;
        uint16_t vPTAT25;
        float alphaPTAT;
        int16_t gainEE;
        float tgc;
        float cpKv;
        float cpKta;
        uint8_t resolutionEE;
        uint8_t calibrationModeEE;
        float KsTa;
        float ksTo[8];
        int16_t ct[8];
        float alpha[192];    
        int16_t offset[2][192];    
        float kta[192];    
        float kv[192];
        float cpAlpha;
        int16_t cpOffset;
        float emissivityEE; 
        uint16_t brokenPixels[2];
    } paramsMLX90641;
    
    int MLX90641_DumpEE(uint8_t slaveAddr, uint16_t *eeData);
    int MLX90641_GetFrameData(uint8_t slaveAddr, uint16_t *frameData);
    int MLX90641_ExtractParameters(uint16_t *eeData, paramsMLX90641 *mlx90641);
    float MLX90641_GetVdd(uint16_t *frameData, const paramsMLX90641 *params);
    float MLX90641_GetTa(uint16_t *frameData, const paramsMLX90641 *params);
    void MLX90641_GetImage(uint16_t *frameData, const paramsMLX90641 *params, float *result);
    void MLX90641_CalculateTo(uint16_t *frameData, const paramsMLX90641 *params, float emissivity, float tr, float *result);
    int MLX90641_SetResolution(uint8_t slaveAddr, uint8_t resolution);
    int MLX90641_GetCurResolution(uint8_t slaveAddr);
    int MLX90641_SetRefreshRate(uint8_t slaveAddr, uint8_t refreshRate);   
    int MLX90641_GetRefreshRate(uint8_t slaveAddr);  
    int MLX90641_GetSubPageNumber(uint16_t *frameData);
    float MLX90641_GetEmissivity(const paramsMLX90641 *mlx90641);
    void MLX90641_BadPixelsCorrection(uint16_t *pixels, float *to, paramsMLX90641 *params);
    
#endif
